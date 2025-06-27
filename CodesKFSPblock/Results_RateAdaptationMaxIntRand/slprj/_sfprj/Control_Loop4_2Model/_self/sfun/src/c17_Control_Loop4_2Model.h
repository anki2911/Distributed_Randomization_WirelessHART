#ifndef __c17_Control_Loop4_2Model_h__
#define __c17_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc17_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc17_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_Control_Loop4_2Model;
  real_T *c17_current_period_1_address;
  int32_T c17_current_period_1_index;
  real_T *c17_last_adaptation_1_address;
  int32_T c17_last_adaptation_1_index;
  real_T *c17_period_index_1_address;
  int32_T c17_period_index_1_index;
  real_T *c17_tau_1_address;
  int32_T c17_tau_1_index;
} SFc17_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc17_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c17_Control_Loop4_2Model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c17_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
