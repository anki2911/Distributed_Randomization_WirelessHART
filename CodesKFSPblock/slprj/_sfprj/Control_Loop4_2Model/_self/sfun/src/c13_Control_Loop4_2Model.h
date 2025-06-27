#ifndef __c13_Control_Loop4_2Model_h__
#define __c13_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc13_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_Control_Loop4_2Model;
  real_T (*c13_P_k_3_address)[16];
  int32_T c13_P_k_3_index;
  real_T (*c13_X_k_3_address)[4];
  int32_T c13_X_k_3_index;
} SFc13_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc13_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c13_Control_Loop4_2Model_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c13_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
