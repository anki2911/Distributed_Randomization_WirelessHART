#ifndef __c15_Control_Loop4_2Model_h__
#define __c15_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc15_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc15_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_isStable;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_Control_Loop4_2Model;
  real_T *c15_current_period_2_address;
  int32_T c15_current_period_2_index;
  real_T *c15_last_adaptation_2_address;
  int32_T c15_last_adaptation_2_index;
  real_T *c15_period_index_2_address;
  int32_T c15_period_index_2_index;
  real_T *c15_tau_2_address;
  int32_T c15_tau_2_index;
} SFc15_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc15_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_Control_Loop4_2Model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c15_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c15_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
