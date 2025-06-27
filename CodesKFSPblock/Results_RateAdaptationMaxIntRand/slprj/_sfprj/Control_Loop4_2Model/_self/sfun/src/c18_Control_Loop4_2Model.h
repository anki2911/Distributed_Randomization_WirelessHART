#ifndef __c18_Control_Loop4_2Model_h__
#define __c18_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc18_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc18_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c18_sfEvent;
  boolean_T c18_isStable;
  boolean_T c18_doneDoubleBufferReInit;
  uint8_T c18_is_active_c18_Control_Loop4_2Model;
  real_T *c18_current_period_4_address;
  int32_T c18_current_period_4_index;
  real_T *c18_last_adaptation_4_address;
  int32_T c18_last_adaptation_4_index;
  real_T *c18_period_index_4_address;
  int32_T c18_period_index_4_index;
  real_T *c18_tau_4_address;
  int32_T c18_tau_4_index;
} SFc18_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc18_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c18_Control_Loop4_2Model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c18_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c18_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
