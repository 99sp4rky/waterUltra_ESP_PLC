TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM waterESP
  VAR
    pulse : BOOL;
    counter_enable : BOOL;
    counter_reset : BOOL;
    counter_q : BOOL;
    counter_max : INT := 10;
    CTU0 : CTU;
    counter_value : INT;
    TON1 : TON;
    TOF0 : TOF;
    R_TRIG1 : R_TRIG;
  END_VAR

  R_TRIG1(CLK := pulse AND counter_enable);
  CTU0(EN := TRUE, CU := R_TRIG1.Q, R := counter_q OR counter_reset, PV := counter_max);
  IF CTU0.ENO THEN
      counter_value := CTU0.CV;
  END_IF;
  counter_q := CTU0.Q;
  TON1(EN := TRUE, IN := NOT(pulse), PT := T#500ms);
  TOF0(EN := TON1.ENO, IN := TON1.Q, PT := T#500ms);
  pulse := TOF0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : waterESP;
  END_RESOURCE
END_CONFIGURATION
