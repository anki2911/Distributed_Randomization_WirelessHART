#ifndef __c16_Control_Loop4_2Model_h__
#define __c16_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc16_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc16_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c16_sfEvent;
  boolean_T c16_isStable;
  boolean_T c16_doneDoubleBufferReInit;
  uint8_T c16_is_active_c16_Control_Loop4_2Model;
  real_T *c16_current_period_3_address;
  int32_T c16_current_period_3_index;
  real_T *c16_last_adaptation_3_address;
  int32_T c16_last_adaptation_3_index;
  real_T *c16_period_index_3_address;
  int32_T c16_period_index_3_index;
  real_T *c16_tau_3_address;
  int32_T c16_tau_3_index;
} SFc16_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc16_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_Control_Loop4_2Model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c16_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
