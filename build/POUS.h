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
  __DECLARE_VAR(INT,CURRENTDISTANCE)
  __DECLARE_VAR(BOOL,FULLG_LED)
  __DECLARE_VAR(INT,FULLG_THRESHOLD)
  __DECLARE_VAR(BOOL,MIDY_LED)
  __DECLARE_VAR(INT,MIDY_THRESHOLD)
  __DECLARE_VAR(BOOL,EMPR_LED)
  __DECLARE_VAR(INT,EMPR_THRESHOLD)
  __DECLARE_VAR(BOOL,SYSSTART_STOP)
  __DECLARE_VAR(BOOL,_TMP_LT7_ENO)
  __DECLARE_VAR(BOOL,_TMP_LT7_OUT)
  __DECLARE_VAR(BOOL,_TMP_LT15_OUT)
  __DECLARE_VAR(BOOL,_TMP_GT14_OUT)
  __DECLARE_VAR(BOOL,_TMP_AND12_ENO)
  __DECLARE_VAR(BOOL,_TMP_AND12_OUT)
  __DECLARE_VAR(BOOL,_TMP_GT4_ENO)
  __DECLARE_VAR(BOOL,_TMP_GT4_OUT)

} WATERESP;

void WATERESP_init__(WATERESP *data__, BOOL retain);
// Code part
void WATERESP_body__(WATERESP *data__);
#endif //__POUS_H
