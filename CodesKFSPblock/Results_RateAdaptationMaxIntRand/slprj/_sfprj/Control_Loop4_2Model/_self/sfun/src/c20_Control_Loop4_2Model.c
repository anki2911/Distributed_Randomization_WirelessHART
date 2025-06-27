/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c20_Control_Loop4_2Model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c20_debug_family_names[8] = { "Period", "nargin", "nargout",
  "y", "period_index_1", "period_index_2", "period_index_3", "period_index_4" };

/* Function Declarations */
static void initialize_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c20_st);
static void finalize_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c20_Control_Loop4_2Model(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void initSimStructsc20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_period_index_4, const char_T
  *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_c_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[16]);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_info_helper(const mxArray **c20_info);
static const mxArray *c20_emlrt_marshallOut(char * c20_u);
static const mxArray *c20_b_emlrt_marshallOut(uint32_T c20_u);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_d_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_e_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_Control_Loop4_2Model, const
  char_T *c20_identifier);
static uint8_T c20_f_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static real_T c20_get_period_index_1(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_period_index_1(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_period_index_1
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b);
static real_T c20_get_period_index_2(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_period_index_2(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_period_index_2
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b);
static real_T c20_get_period_index_3(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_period_index_3(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_period_index_3
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b);
static real_T c20_get_period_index_4(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b);
static void c20_set_period_index_4(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c);
static real_T *c20_access_period_index_4
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b);
static void init_dsm_address_info(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_Control_Loop4_2Model = 0U;
}

static void initialize_params_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T *c20_d_y;
  c20_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2), FALSE);
  c20_hoistedGlobal = *c20_d_y;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_Control_Loop4_2Model;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y, FALSE);
  return c20_st;
}

static void set_sim_state_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c20_st)
{
  const mxArray *c20_u;
  real_T *c20_y;
  c20_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  *c20_y = c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u,
    0)), "y");
  chartInstance->c20_is_active_c20_Control_Loop4_2Model = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_Control_Loop4_2Model");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c20_Control_Loop4_2Model(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[8];
  real_T c20_Period[16];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  real_T c20_y;
  int32_T c20_i0;
  static real_T c20_dv0[16] = { 10.0, 10.0, 15.0, 15.0, 20.0, 20.0, 30.0, 30.0,
    30.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0, 60.0 };

  real_T c20_hoistedGlobal;
  real_T c20_b;
  real_T c20_b_y;
  real_T c20_b_hoistedGlobal;
  real_T c20_b_b;
  real_T c20_c_y;
  real_T c20_c_hoistedGlobal;
  real_T c20_c_b;
  real_T c20_d_y;
  real_T c20_d_hoistedGlobal;
  real_T c20_d_b;
  real_T c20_e_y;
  real_T *c20_f_y;
  c20_f_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c20_f_y, 0U);
  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_Period, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 2U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_y, 3U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c20_period_index_1_address,
    4U, c20_sf_marshallOut, c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c20_period_index_2_address,
    5U, c20_sf_marshallOut, c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c20_period_index_3_address,
    6U, c20_sf_marshallOut, c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c20_period_index_4_address,
    7U, c20_sf_marshallOut, c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 11);
  for (c20_i0 = 0; c20_i0 < 16; c20_i0++) {
    c20_Period[c20_i0] = c20_dv0[c20_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 29);
  c20_hoistedGlobal = c20_get_period_index_1(chartInstance, 0);
  c20_b = c20_hoistedGlobal - 1.0;
  c20_b_y = c20_b;
  c20_b_hoistedGlobal = c20_get_period_index_2(chartInstance, 0);
  c20_b_b = c20_b_hoistedGlobal - 1.0;
  c20_c_y = 10.0 * c20_b_b;
  c20_c_hoistedGlobal = c20_get_period_index_3(chartInstance, 0);
  c20_c_b = c20_c_hoistedGlobal - 1.0;
  c20_d_y = 100.0 * c20_c_b;
  c20_d_hoistedGlobal = c20_get_period_index_4(chartInstance, 0);
  c20_d_b = c20_d_hoistedGlobal - 1.0;
  c20_e_y = 1000.0 * c20_d_b;
  c20_y = ((c20_b_y + c20_c_y) + c20_d_y) + c20_e_y;
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
  *c20_f_y = c20_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc20_Control_Loop4_2Model
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_period_index_4, const char_T
  *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_period_index_4),
    &c20_thisId);
  sf_mex_destroy(&c20_period_index_4);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_period_index_4;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_period_index_4 = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_period_index_4),
    &c20_thisId);
  sf_mex_destroy(&c20_period_index_4);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i1;
  int32_T c20_i2;
  int32_T c20_i3;
  real_T c20_b_inData[16];
  int32_T c20_i4;
  int32_T c20_i5;
  int32_T c20_i6;
  real_T c20_u[16];
  const mxArray *c20_y = NULL;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i1 = 0;
  for (c20_i2 = 0; c20_i2 < 4; c20_i2++) {
    for (c20_i3 = 0; c20_i3 < 4; c20_i3++) {
      c20_b_inData[c20_i3 + c20_i1] = (*(real_T (*)[16])c20_inData)[c20_i3 +
        c20_i1];
    }

    c20_i1 += 4;
  }

  c20_i4 = 0;
  for (c20_i5 = 0; c20_i5 < 4; c20_i5++) {
    for (c20_i6 = 0; c20_i6 < 4; c20_i6++) {
      c20_u[c20_i6 + c20_i4] = c20_b_inData[c20_i6 + c20_i4];
    }

    c20_i4 += 4;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static void c20_c_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  real_T c20_y[16])
{
  real_T c20_dv1[16];
  int32_T c20_i7;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_dv1, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c20_i7 = 0; c20_i7 < 16; c20_i7++) {
    c20_y[c20_i7] = c20_dv1[c20_i7];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_Period;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y[16];
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_Period = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_Period), &c20_thisId,
    c20_y);
  sf_mex_destroy(&c20_Period);
  c20_i8 = 0;
  for (c20_i9 = 0; c20_i9 < 4; c20_i9++) {
    for (c20_i10 = 0; c20_i10 < 4; c20_i10++) {
      (*(real_T (*)[16])c20_outData)[c20_i10 + c20_i8] = c20_y[c20_i10 + c20_i8];
    }

    c20_i8 += 4;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_createstruct("structure", 2, 14, 1),
                FALSE);
  c20_info_helper(&c20_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c20_nameCaptureInfo);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(const mxArray **c20_info)
{
  const mxArray *c20_rhs0 = NULL;
  const mxArray *c20_lhs0 = NULL;
  const mxArray *c20_rhs1 = NULL;
  const mxArray *c20_lhs1 = NULL;
  const mxArray *c20_rhs2 = NULL;
  const mxArray *c20_lhs2 = NULL;
  const mxArray *c20_rhs3 = NULL;
  const mxArray *c20_lhs3 = NULL;
  const mxArray *c20_rhs4 = NULL;
  const mxArray *c20_lhs4 = NULL;
  const mxArray *c20_rhs5 = NULL;
  const mxArray *c20_lhs5 = NULL;
  const mxArray *c20_rhs6 = NULL;
  const mxArray *c20_lhs6 = NULL;
  const mxArray *c20_rhs7 = NULL;
  const mxArray *c20_lhs7 = NULL;
  const mxArray *c20_rhs8 = NULL;
  const mxArray *c20_lhs8 = NULL;
  const mxArray *c20_rhs9 = NULL;
  const mxArray *c20_lhs9 = NULL;
  const mxArray *c20_rhs10 = NULL;
  const mxArray *c20_lhs10 = NULL;
  const mxArray *c20_rhs11 = NULL;
  const mxArray *c20_lhs11 = NULL;
  const mxArray *c20_rhs12 = NULL;
  const mxArray *c20_lhs12 = NULL;
  const mxArray *c20_rhs13 = NULL;
  const mxArray *c20_lhs13 = NULL;
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("mpower"), "name", "name", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c20_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c20_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("ismatrix"), "name", "name",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c20_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("power"), "name", "name", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c20_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c20_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c20_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1358160940U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c20_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c20_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c20_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c20_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c20_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(""), "context", "context", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("mtimes"), "name", "name", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c20_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c20_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("mtimes"), "name", "name", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c20_info, c20_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c20_info, c20_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c20_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c20_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c20_info, sf_mex_duplicatearraysafe(&c20_lhs13), "lhs", "lhs",
                  13);
  sf_mex_destroy(&c20_rhs0);
  sf_mex_destroy(&c20_lhs0);
  sf_mex_destroy(&c20_rhs1);
  sf_mex_destroy(&c20_lhs1);
  sf_mex_destroy(&c20_rhs2);
  sf_mex_destroy(&c20_lhs2);
  sf_mex_destroy(&c20_rhs3);
  sf_mex_destroy(&c20_lhs3);
  sf_mex_destroy(&c20_rhs4);
  sf_mex_destroy(&c20_lhs4);
  sf_mex_destroy(&c20_rhs5);
  sf_mex_destroy(&c20_lhs5);
  sf_mex_destroy(&c20_rhs6);
  sf_mex_destroy(&c20_lhs6);
  sf_mex_destroy(&c20_rhs7);
  sf_mex_destroy(&c20_lhs7);
  sf_mex_destroy(&c20_rhs8);
  sf_mex_destroy(&c20_lhs8);
  sf_mex_destroy(&c20_rhs9);
  sf_mex_destroy(&c20_lhs9);
  sf_mex_destroy(&c20_rhs10);
  sf_mex_destroy(&c20_lhs10);
  sf_mex_destroy(&c20_rhs11);
  sf_mex_destroy(&c20_lhs11);
  sf_mex_destroy(&c20_rhs12);
  sf_mex_destroy(&c20_lhs12);
  sf_mex_destroy(&c20_rhs13);
  sf_mex_destroy(&c20_lhs13);
}

static const mxArray *c20_emlrt_marshallOut(char * c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c20_u)), FALSE);
  return c20_y;
}

static const mxArray *c20_b_emlrt_marshallOut(uint32_T c20_u)
{
  const mxArray *c20_y = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c20_y;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, FALSE);
  return c20_mxArrayOutData;
}

static int32_T c20_d_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i11;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i11, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i11;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_Control_Loop4_2Model, const
  char_T *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_Control_Loop4_2Model), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_Control_Loop4_2Model);
  return c20_y;
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static real_T c20_get_period_index_1(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#222) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_period_index_1_address;
}

static void c20_set_period_index_1(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c20_b);
  if (chartInstance->c20_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#222) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_period_index_1_address = c20_c;
}

static real_T *c20_access_period_index_1
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c20_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#222) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_period_index_1_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c20_c;
}

static real_T c20_get_period_index_2(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#223) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_period_index_2_address;
}

static void c20_set_period_index_2(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c20_b);
  if (chartInstance->c20_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#223) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_period_index_2_address = c20_c;
}

static real_T *c20_access_period_index_2
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c20_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#223) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_period_index_2_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c20_c;
}

static real_T c20_get_period_index_3(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_period_index_3_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_3\' (#224) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_period_index_3_address;
}

static void c20_set_period_index_3(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c20_b);
  if (chartInstance->c20_period_index_3_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_3\' (#224) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_period_index_3_address = c20_c;
}

static real_T *c20_access_period_index_3
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c20_period_index_3_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_3\' (#224) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_period_index_3_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c20_c;
}

static real_T c20_get_period_index_4(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_period_index_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_4\' (#225) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c20_period_index_4_address;
}

static void c20_set_period_index_4(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c20_b, real_T c20_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c20_b);
  if (chartInstance->c20_period_index_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_4\' (#225) in the initialization routine of the chart.\n");
  }

  *chartInstance->c20_period_index_4_address = c20_c;
}

static real_T *c20_access_period_index_4
  (SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c20_b)
{
  real_T *c20_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c20_period_index_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_4\' (#225) in the initialization routine of the chart.\n");
  }

  c20_c = chartInstance->c20_period_index_4_address;
  if (c20_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c20_c;
}

static void init_dsm_address_info(SFc20_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_1", (void **)
    &chartInstance->c20_period_index_1_address,
    &chartInstance->c20_period_index_1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_2", (void **)
    &chartInstance->c20_period_index_2_address,
    &chartInstance->c20_period_index_2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_3", (void **)
    &chartInstance->c20_period_index_3_address,
    &chartInstance->c20_period_index_3_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_4", (void **)
    &chartInstance->c20_period_index_4_address,
    &chartInstance->c20_period_index_4_index);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c20_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(682073914U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1922538592U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3393506513U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(450182957U);
}

mxArray *sf_c20_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5H3LD3L3TgFArjtzQYePGD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c20_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           20,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Control_Loop4_2ModelMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Control_Loop4_2ModelMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Control_Loop4_2ModelMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"y");
          _SFD_SET_DATA_PROPS(1,11,0,0,"period_index_1");
          _SFD_SET_DATA_PROPS(2,11,0,0,"period_index_2");
          _SFD_SET_DATA_PROPS(3,11,0,0,"period_index_3");
          _SFD_SET_DATA_PROPS(4,11,0,0,"period_index_4");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,832);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);

        {
          real_T *c20_y;
          c20_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c20_y);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c20_period_index_1_address);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c20_period_index_2_address);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c20_period_index_3_address);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_period_index_4_address);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Control_Loop4_2ModelMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "eh53oiUbOucoNgGT07svWC";
}

static void sf_opaque_initialize_c20_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_Control_Loop4_2Model
    ((SFc20_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c20_Control_Loop4_2Model((SFc20_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c20_Control_Loop4_2Model((SFc20_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c20_Control_Loop4_2Model((SFc20_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c20_Control_Loop4_2Model((SFc20_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_Control_Loop4_2Model
    ((SFc20_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c20_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_Control_Loop4_2Model
    ((SFc20_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c20_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c20_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c20_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c20_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c20_Control_Loop4_2Model((SFc20_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_Control_Loop4_2Model
    ((SFc20_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_Control_Loop4_2Model
      ((SFc20_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,20,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(128531827U));
  ssSetChecksum1(S,(2664814394U));
  ssSetChecksum2(S,(1443215913U));
  ssSetChecksum3(S,(2092869216U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c20_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_Control_Loop4_2Model(SimStruct *S)
{
  SFc20_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc20_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc20_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_Control_Loop4_2Model;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c20_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
