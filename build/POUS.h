#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM WATERESP
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,PULSE)
  __DECLARE_LOCATED(BOOL,COUNTER_ENABLE)
  __DECLARE_LOCATED(BOOL,COUNTER_RESET)
  __DECLARE_LOCATED(BOOL,COUNTER_Q)
  __DECLARE_LOCATED(INT,COUNTER_MAX)
  CTU CTU0;
  __DECLARE_VAR(INT,COUNTER_VALUE)
  TON TON1;
  TOF TOF0;
  R_TRIG R_TRIG1;

} WATERESP;

void WATERESP_init__(WATERESP *data__, BOOL retain);
// Code part
void WATERESP_body__(WATERESP *data__);
#endif //__POUS_H
