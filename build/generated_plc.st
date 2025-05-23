PROGRAM waterESP
  VAR_EXTERNAL
    DISTANCE : INT;
    DISTANCE_READY : BOOL;
  END_VAR
  VAR
    currentDistance : INT;
  END_VAR
  VAR
    fullG_LED AT %QX0.1 : BOOL;
  END_VAR
  VAR
    fullG_threshold : INT := 20;
  END_VAR
  VAR
    midY_LED AT %QX0.2 : BOOL;
  END_VAR
  VAR
    midY_threshold : INT := 50;
  END_VAR
  VAR
    empR_LED AT %QX0.3 : BOOL;
  END_VAR
  VAR
    empR_threshold : INT := 50;
    _TMP_MOVE24_ENO : BOOL;
    _TMP_MOVE24_OUT : INT;
    _TMP_LT15_OUT : BOOL;
    _TMP_GT14_OUT : BOOL;
    _TMP_AND12_ENO : BOOL;
    _TMP_AND12_OUT : BOOL;
    _TMP_GE4_ENO : BOOL;
    _TMP_GE4_OUT : BOOL;
    _TMP_LT7_ENO : BOOL;
    _TMP_LT7_OUT : BOOL;
  END_VAR

  _TMP_MOVE24_OUT := MOVE(EN := TRUE, IN := DISTANCE, ENO => _TMP_MOVE24_ENO);
  IF _TMP_MOVE24_ENO THEN
      currentDistance := _TMP_MOVE24_OUT;
  END_IF;
  _TMP_LT15_OUT := LT(currentDistance, midY_threshold);
  _TMP_GT14_OUT := GT(currentDistance, fullG_threshold);
  _TMP_AND12_OUT := AND(EN := TRUE, IN1 := _TMP_LT15_OUT, IN2 := _TMP_GT14_OUT, ENO => _TMP_AND12_ENO);
  midY_LED := _TMP_AND12_OUT;
  _TMP_GE4_OUT := GE(EN := TRUE, IN1 := currentDistance, IN2 := empR_threshold, ENO => _TMP_GE4_ENO);
  empR_LED := _TMP_GE4_OUT;
  _TMP_LT7_OUT := LT(EN := TRUE, IN1 := currentDistance, IN2 := fullG_threshold, ENO => _TMP_LT7_ENO);
  fullG_LED := _TMP_LT7_OUT;
END_PROGRAM


CONFIGURATION Config0
  VAR_GLOBAL
    DISTANCE : INT;
    DISTANCE_READY : BOOL;
  END_VAR

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : waterESP;
  END_RESOURCE
END_CONFIGURATION
