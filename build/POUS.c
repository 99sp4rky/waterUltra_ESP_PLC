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





void WATERESP_init__(WATERESP *data__, BOOL retain) {
  __INIT_VAR(data__->PULSE,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_0,data__->COUNTER_ENABLE,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_ENABLE,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_1,data__->COUNTER_RESET,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_RESET,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->COUNTER_Q,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_Q,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(INT,__QW0,data__->COUNTER_MAX,retain)
  __INIT_LOCATED_VALUE(data__->COUNTER_MAX,10)
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->COUNTER_VALUE,0,retain)
  TON_init__(&data__->TON1,retain);
  TOF_init__(&data__->TOF0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void WATERESP_body__(WATERESP *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->PULSE,) && __GET_LOCATED(data__->COUNTER_ENABLE,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,(__GET_LOCATED(data__->COUNTER_Q,) || __GET_LOCATED(data__->COUNTER_RESET,)));
  __SET_VAR(data__->CTU0.,PV,,__GET_LOCATED(data__->COUNTER_MAX,));
  CTU_body__(&data__->CTU0);
  if (__GET_VAR(data__->CTU0.ENO,)) {
    __SET_VAR(data__->,COUNTER_VALUE,,__GET_VAR(data__->CTU0.CV,));
  };
  __SET_LOCATED(data__->,COUNTER_Q,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->TON1.,EN,,__BOOL_LITERAL(TRUE));
  __SET_VAR(data__->TON1.,IN,,!(__GET_VAR(data__->PULSE,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TOF0.,EN,,__GET_VAR(data__->TON1.ENO,));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,PULSE,,__GET_VAR(data__->TOF0.Q,));

  goto __end;

__end:
  return;
} // WATERESP_body__() 





