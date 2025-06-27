#ifndef __c4_Control_Loop4_2Model_h__
#define __c4_Control_Loop4_2Model_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_Control_Loop4_2ModelInstanceStruct
#define typedef_SFc4_Control_Loop4_2ModelInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Control_Loop4_2Model;
} SFc4_Control_Loop4_2ModelInstanceStruct;

#endif                                 /*typedef_SFc4_Control_Loop4_2ModelInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Control_Loop4_2Model_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
extern void c4_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
