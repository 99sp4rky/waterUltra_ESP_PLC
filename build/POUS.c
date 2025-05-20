void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





static inline BOOL __WATERESP_LT__BOOL__INT1(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  WATERESP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_LT7_ENO,);
  __res = LT__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_LT7_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __WATERESP_AND__BOOL__BOOL2(BOOL EN,
  UINT __PARAM_COUNT,
  BOOL IN1,
  BOOL IN2,
  WATERESP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_AND12_ENO,);
  __res = AND__BOOL__BOOL(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_AND12_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __WATERESP_GT__BOOL__INT3(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  WATERESP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_GT4_ENO,);
  __res = GT__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_GT4_ENO,,__TMP_ENO);
  return __res;
}

void WATERESP_init__(WATERESP *data__, BOOL retain) {
  __INIT_VAR(data__->CURRENTDISTANCE,0,retain)
  __INIT_VAR(data__->FULLG_LED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FULLG_THRESHOLD,20,retain)
  __INIT_VAR(data__->MIDY_LED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MIDY_THRESHOLD,50,retain)
  __INIT_VAR(data__->EMPR_LED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->EMPR_THRESHOLD,50,retain)
  __INIT_VAR(data__->SYSSTART_STOP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LT15_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND12_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT4_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GT4_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void WATERESP_body__(WATERESP *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_LT7_OUT,,__WATERESP_LT__BOOL__INT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTDISTANCE,),
    (INT)__GET_VAR(data__->FULLG_THRESHOLD,),
    data__));
  __SET_VAR(data__->,FULLG_LED,,__GET_VAR(data__->_TMP_LT7_OUT,));
  __SET_VAR(data__->,_TMP_LT15_OUT,,LT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTDISTANCE,),
    (INT)__GET_VAR(data__->MIDY_THRESHOLD,)));
  __SET_VAR(data__->,_TMP_GT14_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTDISTANCE,),
    (INT)__GET_VAR(data__->FULLG_THRESHOLD,)));
  __SET_VAR(data__->,_TMP_AND12_OUT,,__WATERESP_AND__BOOL__BOOL2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LT15_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GT14_OUT,),
    data__));
  __SET_VAR(data__->,MIDY_LED,,__GET_VAR(data__->_TMP_AND12_OUT,));
  __SET_VAR(data__->,_TMP_GT4_OUT,,__WATERESP_GT__BOOL__INT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->CURRENTDISTANCE,),
    (INT)__GET_VAR(data__->EMPR_THRESHOLD,),
    data__));
  __SET_VAR(data__->,MIDY_LED,,__GET_VAR(data__->_TMP_GT4_OUT,));

  goto __end;

__end:
  return;
} // WATERESP_body__() 





