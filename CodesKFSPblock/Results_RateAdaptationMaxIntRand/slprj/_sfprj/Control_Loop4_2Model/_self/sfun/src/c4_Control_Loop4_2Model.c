/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c4_Control_Loop4_2Model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[16] = { "nargin", "nargout", "u1",
  "u2", "x1_prev", "x2_prev", "x3_prev", "x4_prev", "y1", "y2", "y3", "y4", "x1",
  "x2", "x3", "x4" };

/* Function Declarations */
static void initialize_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c4_Control_Loop4_2Model(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initSimStructsc4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_x4, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(const mxArray **c4_info);
static const mxArray *c4_emlrt_marshallOut(char * c4_u);
static const mxArray *c4_b_emlrt_marshallOut(uint32_T c4_u);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Control_Loop4_2Model, const
  char_T *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Control_Loop4_2Model = 0U;
}

static void initialize_params_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T c4_e_hoistedGlobal;
  real_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T c4_f_hoistedGlobal;
  real_T c4_f_u;
  const mxArray *c4_g_y = NULL;
  real_T c4_g_hoistedGlobal;
  real_T c4_g_u;
  const mxArray *c4_h_y = NULL;
  real_T c4_h_hoistedGlobal;
  real_T c4_h_u;
  const mxArray *c4_i_y = NULL;
  uint8_T c4_i_hoistedGlobal;
  uint8_T c4_i_u;
  const mxArray *c4_j_y = NULL;
  real_T *c4_x1;
  real_T *c4_x2;
  real_T *c4_x3;
  real_T *c4_x4;
  real_T *c4_y1;
  real_T *c4_y2;
  real_T *c4_y3;
  real_T *c4_y4;
  c4_x4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_x3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_x2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(9), FALSE);
  c4_hoistedGlobal = *c4_x1;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_x2;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_x3;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_x4;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = *c4_y1;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = *c4_y2;
  c4_f_u = c4_f_hoistedGlobal;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = *c4_y3;
  c4_g_u = c4_g_hoistedGlobal;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_h_hoistedGlobal = *c4_y4;
  c4_h_u = c4_h_hoistedGlobal;
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y", &c4_h_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  c4_i_hoistedGlobal = chartInstance->c4_is_active_c4_Control_Loop4_2Model;
  c4_i_u = c4_i_hoistedGlobal;
  c4_j_y = NULL;
  sf_mex_assign(&c4_j_y, sf_mex_create("y", &c4_i_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 8, c4_j_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_x1;
  real_T *c4_x2;
  real_T *c4_x3;
  real_T *c4_x4;
  real_T *c4_y1;
  real_T *c4_y2;
  real_T *c4_y3;
  real_T *c4_y4;
  c4_x4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_x3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_x2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_x1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "x1");
  *c4_x2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "x2");
  *c4_x3 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
    "x3");
  *c4_x4 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "x4");
  *c4_y1 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
    "y1");
  *c4_y2 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 5)),
    "y2");
  *c4_y3 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 6)),
    "y3");
  *c4_y4 = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 7)),
    "y4");
  chartInstance->c4_is_active_c4_Control_Loop4_2Model = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 8)),
     "is_active_c4_Control_Loop4_2Model");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c4_Control_Loop4_2Model(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  real_T *c4_u1;
  real_T *c4_u2;
  real_T *c4_y1;
  real_T *c4_y2;
  real_T *c4_y3;
  real_T *c4_y4;
  real_T *c4_x1;
  real_T *c4_x2;
  real_T *c4_x3;
  real_T *c4_x4;
  real_T *c4_x1_prev;
  real_T *c4_x2_prev;
  real_T *c4_x3_prev;
  real_T *c4_x4_prev;
  c4_x4_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_x3_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_x2_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_x1_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_x4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_x3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_x2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_u1, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_u2, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_y1, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_y2, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_y3, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_y4, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_x1, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_x2, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_x3, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_x4, 9U);
  _SFD_DATA_RANGE_CHECK(*c4_x1_prev, 10U);
  _SFD_DATA_RANGE_CHECK(*c4_x2_prev, 11U);
  _SFD_DATA_RANGE_CHECK(*c4_x3_prev, 12U);
  _SFD_DATA_RANGE_CHECK(*c4_x4_prev, 13U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_Control_Loop4_2Model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_u1;
  real_T c4_u2;
  real_T c4_x1_prev;
  real_T c4_x2_prev;
  real_T c4_x3_prev;
  real_T c4_x4_prev;
  uint32_T c4_debug_family_var_map[16];
  real_T c4_nargin = 6.0;
  real_T c4_nargout = 8.0;
  real_T c4_y1;
  real_T c4_y2;
  real_T c4_y3;
  real_T c4_y4;
  real_T c4_x1;
  real_T c4_x2;
  real_T c4_x3;
  real_T c4_x4;
  real_T c4_a;
  real_T c4_y;
  real_T c4_b_a;
  real_T c4_b_y;
  real_T c4_c_a;
  real_T c4_c_y;
  real_T c4_d_a;
  real_T c4_d_y;
  real_T c4_e_a;
  real_T c4_e_y;
  real_T c4_f_a;
  real_T c4_f_y;
  real_T c4_g_a;
  real_T c4_g_y;
  real_T c4_h_a;
  real_T c4_h_y;
  real_T *c4_b_u1;
  real_T *c4_b_u2;
  real_T *c4_b_x1_prev;
  real_T *c4_b_x2_prev;
  real_T *c4_b_x3_prev;
  real_T *c4_b_x4_prev;
  real_T *c4_b_y1;
  real_T *c4_b_y2;
  real_T *c4_b_y3;
  real_T *c4_b_y4;
  real_T *c4_b_x1;
  real_T *c4_b_x2;
  real_T *c4_b_x3;
  real_T *c4_b_x4;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  boolean_T guard4 = FALSE;
  c4_b_x4_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_x3_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_x2_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_x1_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_x4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
  c4_b_x3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
  c4_b_x2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c4_b_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c4_b_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_u1;
  c4_b_hoistedGlobal = *c4_b_u2;
  c4_c_hoistedGlobal = *c4_b_x1_prev;
  c4_d_hoistedGlobal = *c4_b_x2_prev;
  c4_e_hoistedGlobal = *c4_b_x3_prev;
  c4_f_hoistedGlobal = *c4_b_x4_prev;
  c4_u1 = c4_hoistedGlobal;
  c4_u2 = c4_b_hoistedGlobal;
  c4_x1_prev = c4_c_hoistedGlobal;
  c4_x2_prev = c4_d_hoistedGlobal;
  c4_x3_prev = c4_e_hoistedGlobal;
  c4_x4_prev = c4_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_u1, 2U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_u2, 3U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x1_prev, 4U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x2_prev, 5U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x3_prev, 6U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_x4_prev, 7U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y1, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y2, 9U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y3, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_y4, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x1, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x2, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x3, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_x4, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, c4_u1 >= 1000.0)) {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
    c4_u1 -= 1000.0;
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
    if (CV_EML_IF(0, 1, 1, c4_u2 >= 3000.0)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
      c4_u2 -= 3000.0;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
      c4_a = c4_u2;
      c4_y = c4_a * 0.001;
      c4_y4 = -(c4_u1 + c4_y);
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
      c4_y3 = c4_x3_prev;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 11);
      c4_y2 = c4_x2_prev;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
      c4_y1 = c4_x1_prev;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
      guard3 = FALSE;
      if (CV_EML_COND(0, 1, 0, c4_u2 < 3000.0)) {
        if (CV_EML_COND(0, 1, 1, c4_u2 >= 2000.0)) {
          CV_EML_MCDC(0, 1, 0, TRUE);
          CV_EML_IF(0, 1, 2, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
          c4_u2 -= 2000.0;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 15);
          c4_y4 = c4_x4_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 16);
          c4_b_a = c4_u2;
          c4_b_y = c4_b_a * 0.001;
          c4_y3 = -(c4_u1 + c4_b_y);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 17);
          c4_y2 = c4_x2_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 18);
          c4_y1 = c4_x1_prev;
        } else {
          guard3 = TRUE;
        }
      } else {
        guard3 = TRUE;
      }

      if (guard3 == TRUE) {
        CV_EML_MCDC(0, 1, 0, FALSE);
        CV_EML_IF(0, 1, 2, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 19);
        guard4 = FALSE;
        if (CV_EML_COND(0, 1, 2, c4_u2 < 2000.0)) {
          if (CV_EML_COND(0, 1, 3, c4_u2 >= 1000.0)) {
            CV_EML_MCDC(0, 1, 1, TRUE);
            CV_EML_IF(0, 1, 3, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 20);
            c4_u2 -= 1000.0;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 21);
            c4_y4 = c4_x4_prev;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 22);
            c4_y3 = c4_x3_prev;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 23);
            c4_c_a = c4_u2;
            c4_c_y = c4_c_a * 0.001;
            c4_y2 = -(c4_u1 + c4_c_y);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 24);
            c4_y1 = c4_x1_prev;
          } else {
            guard4 = TRUE;
          }
        } else {
          guard4 = TRUE;
        }

        if (guard4 == TRUE) {
          CV_EML_MCDC(0, 1, 1, FALSE);
          CV_EML_IF(0, 1, 3, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 26);
          c4_y4 = c4_x4_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 27);
          c4_y3 = c4_x3_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 28);
          c4_y2 = c4_x2_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 29);
          c4_d_a = c4_u2;
          c4_d_y = c4_d_a * 0.001;
          c4_y1 = -(c4_u1 + c4_d_y);
        }
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 32);
    if (CV_EML_IF(0, 1, 4, c4_u2 >= 3000.0)) {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 33);
      c4_u2 -= 3000.0;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 34);
      c4_e_a = c4_u2;
      c4_e_y = c4_e_a * 0.001;
      c4_y4 = c4_u1 + c4_e_y;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 35);
      c4_y3 = c4_x3_prev;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 36);
      c4_y2 = c4_x2_prev;
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 37);
      c4_y1 = c4_x1_prev;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 38);
      guard1 = FALSE;
      if (CV_EML_COND(0, 1, 4, c4_u2 < 3000.0)) {
        if (CV_EML_COND(0, 1, 5, c4_u2 >= 2000.0)) {
          CV_EML_MCDC(0, 1, 2, TRUE);
          CV_EML_IF(0, 1, 5, TRUE);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 39);
          c4_u2 -= 2000.0;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 40);
          c4_y4 = c4_x4_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 41);
          c4_f_a = c4_u2;
          c4_f_y = c4_f_a * 0.001;
          c4_y3 = c4_u1 + c4_f_y;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 42);
          c4_y2 = c4_x2_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 43);
          c4_y1 = c4_x1_prev;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        CV_EML_MCDC(0, 1, 2, FALSE);
        CV_EML_IF(0, 1, 5, FALSE);
        _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 44);
        guard2 = FALSE;
        if (CV_EML_COND(0, 1, 6, c4_u2 < 2000.0)) {
          if (CV_EML_COND(0, 1, 7, c4_u2 >= 1000.0)) {
            CV_EML_MCDC(0, 1, 3, TRUE);
            CV_EML_IF(0, 1, 6, TRUE);
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 45);
            c4_u2 -= 1000.0;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 46);
            c4_y4 = c4_x4_prev;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 47);
            c4_y3 = c4_x3_prev;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 48);
            c4_g_a = c4_u2;
            c4_g_y = c4_g_a * 0.001;
            c4_y2 = c4_u1 + c4_g_y;
            _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 49);
            c4_y1 = c4_x1_prev;
          } else {
            guard2 = TRUE;
          }
        } else {
          guard2 = TRUE;
        }

        if (guard2 == TRUE) {
          CV_EML_MCDC(0, 1, 3, FALSE);
          CV_EML_IF(0, 1, 6, FALSE);
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 51);
          c4_y4 = c4_x4_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 52);
          c4_y3 = c4_x3_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 53);
          c4_y2 = c4_x2_prev;
          _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 54);
          c4_h_a = c4_u2;
          c4_h_y = c4_h_a * 0.001;
          c4_y1 = c4_u1 + c4_h_y;
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 57);
  c4_x4 = c4_y4;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 58);
  c4_x3 = c4_y3;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 59);
  c4_x2 = c4_y2;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 60);
  c4_x1 = c4_y1;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -60);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_y1 = c4_y1;
  *c4_b_y2 = c4_y2;
  *c4_b_y3 = c4_y3;
  *c4_b_y4 = c4_y4;
  *c4_b_x1 = c4_x1;
  *c4_b_x2 = c4_x2;
  *c4_b_x3 = c4_x3;
  *c4_b_x4 = c4_x4;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_Control_Loop4_2Model
  (SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_x4, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_x4), &c4_thisId);
  sf_mex_destroy(&c4_x4);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_x4;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c4_x4 = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_x4), &c4_thisId);
  sf_mex_destroy(&c4_x4);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_createstruct("structure", 2, 2, 1),
                FALSE);
  c4_info_helper(&c4_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(const mxArray **c4_info)
{
  const mxArray *c4_rhs0 = NULL;
  const mxArray *c4_lhs0 = NULL;
  const mxArray *c4_rhs1 = NULL;
  const mxArray *c4_lhs1 = NULL;
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c4_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c4_info, c4_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c4_info, c4_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c4_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c4_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c4_info, sf_mex_duplicatearraysafe(&c4_lhs1), "lhs", "lhs", 1);
  sf_mex_destroy(&c4_rhs0);
  sf_mex_destroy(&c4_lhs0);
  sf_mex_destroy(&c4_rhs1);
  sf_mex_destroy(&c4_lhs1);
}

static const mxArray *c4_emlrt_marshallOut(char * c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c4_u)), FALSE);
  return c4_y;
}

static const mxArray *c4_b_emlrt_marshallOut(uint32_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c4_y;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i0, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Control_Loop4_2Model, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Control_Loop4_2Model), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Control_Loop4_2Model);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
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

void sf_c4_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1858860839U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(293433544U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3496327701U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4235697195U);
}

mxArray *sf_c4_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("IZFkUZTmMCx1XRGJ2P2gF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[21],T\"x1\",},{M[1],M[22],T\"x2\",},{M[1],M[23],T\"x3\",},{M[1],M[24],T\"x4\",},{M[1],M[5],T\"y1\",},{M[1],M[27],T\"y2\",},{M[1],M[28],T\"y3\",},{M[1],M[29],T\"y4\",},{M[8],M[0],T\"is_active_c4_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           4,
           1,
           1,
           14,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u1");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u2");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y1");
          _SFD_SET_DATA_PROPS(3,2,0,1,"y2");
          _SFD_SET_DATA_PROPS(4,2,0,1,"y3");
          _SFD_SET_DATA_PROPS(5,2,0,1,"y4");
          _SFD_SET_DATA_PROPS(6,2,0,1,"x1");
          _SFD_SET_DATA_PROPS(7,2,0,1,"x2");
          _SFD_SET_DATA_PROPS(8,2,0,1,"x3");
          _SFD_SET_DATA_PROPS(9,2,0,1,"x4");
          _SFD_SET_DATA_PROPS(10,1,1,0,"x1_prev");
          _SFD_SET_DATA_PROPS(11,1,1,0,"x2_prev");
          _SFD_SET_DATA_PROPS(12,1,1,0,"x3_prev");
          _SFD_SET_DATA_PROPS(13,1,1,0,"x4_prev");
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
        _SFD_CV_INIT_EML(0,1,1,7,0,0,0,0,0,8,4);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1318);
        _SFD_CV_INIT_EML_IF(0,1,0,92,107,703,1278);
        _SFD_CV_INIT_EML_IF(0,1,1,132,147,274,702);
        _SFD_CV_INIT_EML_IF(0,1,2,274,306,433,702);
        _SFD_CV_INIT_EML_IF(0,1,3,433,465,592,702);
        _SFD_CV_INIT_EML_IF(0,1,4,712,727,852,1274);
        _SFD_CV_INIT_EML_IF(0,1,5,852,884,1009,1274);
        _SFD_CV_INIT_EML_IF(0,1,6,1009,1041,1166,1274);

        {
          static int condStart[] = { 282, 295 };

          static int condEnd[] = { 291, 305 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,282,305,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 441, 454 };

          static int condEnd[] = { 450, 464 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,441,464,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 860, 873 };

          static int condEnd[] = { 869, 883 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,860,883,2,4,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1017, 1030 };

          static int condEnd[] = { 1026, 1040 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,3,1017,1040,2,6,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_u1;
          real_T *c4_u2;
          real_T *c4_y1;
          real_T *c4_y2;
          real_T *c4_y3;
          real_T *c4_y4;
          real_T *c4_x1;
          real_T *c4_x2;
          real_T *c4_x3;
          real_T *c4_x4;
          real_T *c4_x1_prev;
          real_T *c4_x2_prev;
          real_T *c4_x3_prev;
          real_T *c4_x4_prev;
          c4_x4_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c4_x3_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_x2_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_x1_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_x4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 8);
          c4_x3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 7);
          c4_x2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 6);
          c4_x1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c4_y4 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_y3 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c4_y2 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_u2 = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_u1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_u1);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_u2);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_y1);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_y2);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_y3);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_y4);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_x1);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_x2);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_x3);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_x4);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_x1_prev);
          _SFD_SET_DATA_VALUE_PTR(11U, c4_x2_prev);
          _SFD_SET_DATA_VALUE_PTR(12U, c4_x3_prev);
          _SFD_SET_DATA_VALUE_PTR(13U, c4_x4_prev);
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
  return "XyvTXncbz1P178UGHdjXoB";
}

static void sf_opaque_initialize_c4_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Control_Loop4_2Model
    ((SFc4_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Control_Loop4_2Model
    ((SFc4_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Control_Loop4_2Model();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c4_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c4_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Control_Loop4_2Model((SFc4_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Control_Loop4_2Model
      ((SFc4_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,8);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3850199536U));
  ssSetChecksum1(S,(3872510301U));
  ssSetChecksum2(S,(1860510787U));
  ssSetChecksum3(S,(1950426954U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Control_Loop4_2Model(SimStruct *S)
{
  SFc4_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc4_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc4_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Control_Loop4_2Model;
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

void c4_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
