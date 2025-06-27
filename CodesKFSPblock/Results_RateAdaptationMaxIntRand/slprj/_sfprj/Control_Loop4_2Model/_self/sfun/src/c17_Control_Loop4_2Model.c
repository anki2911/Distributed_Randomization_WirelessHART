/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c17_Control_Loop4_2Model.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c17_debug_family_names[22] = { "candidate_period",
  "no_of_candidates", "alpha_1", "alpha_2", "beta", "X_SE2", "Lambda", "Vlth",
  "Vdth", "nargin", "nargout", "timer", "Vxt", "t0", "Vxt0_1", "y", "t1", "Vxt0",
  "tau_1", "current_period_1", "period_index_1", "last_adaptation_1" };

/* Function Declarations */
static void initialize_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c17_update_debugger_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c17_st);
static void finalize_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c17_Control_Loop4_2Model(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c17_chartstep_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initSimStructsc17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_last_adaptation_1, const char_T
  *c17_identifier);
static real_T c17_b_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_c_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[4]);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(uint32_T c17_u);
static void c17_eml_scalar_eg(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_d_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_e_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Control_Loop4_2Model, const
  char_T *c17_identifier);
static uint8_T c17_f_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static real_T c17_get_current_period_1(SFc17_Control_Loop4_2ModelInstanceStruct *
  chartInstance, uint32_T c17_b);
static void c17_set_current_period_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c);
static real_T *c17_access_current_period_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b);
static real_T c17_get_last_adaptation_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b);
static void c17_set_last_adaptation_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c);
static real_T *c17_access_last_adaptation_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b);
static real_T c17_get_period_index_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b);
static void c17_set_period_index_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c);
static real_T *c17_access_period_index_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b);
static real_T c17_get_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b);
static void c17_set_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c);
static real_T *c17_access_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b);
static void init_dsm_address_info(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_is_active_c17_Control_Loop4_2Model = 0U;
}

static void initialize_params_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c17_update_debugger_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  real_T c17_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  real_T c17_b_hoistedGlobal;
  real_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T c17_c_hoistedGlobal;
  real_T c17_c_u;
  const mxArray *c17_d_y = NULL;
  uint8_T c17_d_hoistedGlobal;
  uint8_T c17_d_u;
  const mxArray *c17_e_y = NULL;
  real_T *c17_Vxt0;
  real_T *c17_t1;
  real_T *c17_f_y;
  c17_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c17_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c17_f_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellarray(4), FALSE);
  c17_hoistedGlobal = *c17_Vxt0;
  c17_u = c17_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = *c17_t1;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  c17_c_hoistedGlobal = *c17_f_y;
  c17_c_u = c17_c_hoistedGlobal;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 2, c17_d_y);
  c17_d_hoistedGlobal = chartInstance->c17_is_active_c17_Control_Loop4_2Model;
  c17_d_u = c17_d_hoistedGlobal;
  c17_e_y = NULL;
  sf_mex_assign(&c17_e_y, sf_mex_create("y", &c17_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c17_y, 3, c17_e_y);
  sf_mex_assign(&c17_st, c17_y, FALSE);
  return c17_st;
}

static void set_sim_state_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c17_st)
{
  const mxArray *c17_u;
  real_T *c17_Vxt0;
  real_T *c17_t1;
  real_T *c17_y;
  c17_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c17_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c17_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = TRUE;
  c17_u = sf_mex_dup(c17_st);
  *c17_Vxt0 = c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c17_u, 0)), "Vxt0");
  *c17_t1 = c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u,
    1)), "t1");
  *c17_y = c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u,
    2)), "y");
  chartInstance->c17_is_active_c17_Control_Loop4_2Model = c17_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 3)),
     "is_active_c17_Control_Loop4_2Model");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c17_Control_Loop4_2Model(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  real_T *c17_timer;
  real_T *c17_Vxt;
  real_T *c17_y;
  real_T *c17_t0;
  real_T *c17_t1;
  real_T *c17_Vxt0_1;
  real_T *c17_Vxt0;
  c17_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c17_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c17_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c17_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c17_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c17_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c17_timer, 0U);
  _SFD_DATA_RANGE_CHECK(*c17_Vxt, 1U);
  _SFD_DATA_RANGE_CHECK(*c17_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c17_t0, 4U);
  _SFD_DATA_RANGE_CHECK(*c17_t1, 5U);
  _SFD_DATA_RANGE_CHECK(*c17_Vxt0_1, 6U);
  _SFD_DATA_RANGE_CHECK(*c17_Vxt0, 7U);
  chartInstance->c17_sfEvent = CALL_EVENT;
  c17_chartstep_c17_Control_Loop4_2Model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c17_chartstep_c17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  real_T c17_hoistedGlobal;
  real_T c17_b_hoistedGlobal;
  real_T c17_c_hoistedGlobal;
  real_T c17_d_hoistedGlobal;
  real_T c17_timer;
  real_T c17_Vxt;
  real_T c17_t0;
  real_T c17_Vxt0_1;
  uint32_T c17_debug_family_var_map[22];
  real_T c17_candidate_period[4];
  real_T c17_no_of_candidates;
  real_T c17_alpha_1;
  real_T c17_alpha_2;
  real_T c17_beta;
  real_T c17_X_SE2;
  real_T c17_Lambda;
  real_T c17_Vlth;
  real_T c17_Vdth;
  real_T c17_nargin = 4.0;
  real_T c17_nargout = 3.0;
  real_T c17_y;
  real_T c17_t1;
  real_T c17_Vxt0;
  int32_T c17_i0;
  static real_T c17_dv0[4] = { 10.0, 20.0, 30.0, 60.0 };

  real_T c17_e_hoistedGlobal;
  real_T c17_u;
  const mxArray *c17_b_y = NULL;
  real_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T c17_c_u;
  const mxArray *c17_d_y = NULL;
  real_T c17_d_u;
  const mxArray *c17_e_y = NULL;
  int32_T c17_i1;
  static char_T c17_cv0[5] = { 'H', 'e', 'l', 'l', 'o' };

  char_T c17_e_u[5];
  const mxArray *c17_f_y = NULL;
  int32_T c17_i2;
  static char_T c17_cv1[20] = { 'I', 'n', 's', 'i', 'd', 'e', ' ', 'R', 'a', 't',
    'e', ' ', 'I', 'n', 'c', 'r', 'e', 'a', 's', 'e' };

  char_T c17_f_u[20];
  const mxArray *c17_g_y = NULL;
  int32_T c17_i3;
  static char_T c17_cv2[11] = { 'I', 'n', 's', 'i', 'd', 'e', ' ', 'l', 'a', '_',
    '1' };

  char_T c17_g_u[11];
  const mxArray *c17_h_y = NULL;
  int32_T c17_i4;
  static char_T c17_cv3[2] = { 'H', 'i' };

  char_T c17_h_u[2];
  const mxArray *c17_i_y = NULL;
  real_T c17_b;
  real_T c17_b_b;
  real_T c17_c_b;
  real_T c17_bk;
  real_T c17_d_b;
  real_T c17_br;
  real_T c17_c;
  real_T c17_a;
  real_T c17_e_b;
  real_T c17_j_y;
  int32_T c17_i5;
  static char_T c17_cv4[3] = { 'H', 'e', 'y' };

  char_T c17_i_u[3];
  const mxArray *c17_k_y = NULL;
  int32_T c17_i6;
  static char_T c17_cv5[4] = { 'H', 'i', 'H', 'i' };

  char_T c17_j_u[4];
  const mxArray *c17_l_y = NULL;
  real_T c17_k_u;
  const mxArray *c17_m_y = NULL;
  real_T *c17_b_Vxt0;
  real_T *c17_b_t1;
  real_T *c17_n_y;
  real_T *c17_b_Vxt0_1;
  real_T *c17_b_t0;
  real_T *c17_b_Vxt;
  real_T *c17_b_timer;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c17_b_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c17_b_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c17_b_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c17_b_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c17_n_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c17_b_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c17_b_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  c17_hoistedGlobal = *c17_b_timer;
  c17_b_hoistedGlobal = *c17_b_Vxt;
  c17_c_hoistedGlobal = *c17_b_t0;
  c17_d_hoistedGlobal = *c17_b_Vxt0_1;
  c17_timer = c17_hoistedGlobal;
  c17_Vxt = c17_b_hoistedGlobal;
  c17_t0 = c17_c_hoistedGlobal;
  c17_Vxt0_1 = c17_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_candidate_period, 0U,
    c17_b_sf_marshallOut, c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_no_of_candidates, 1U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_alpha_1, 2U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_alpha_2, 3U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_beta, 4U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_X_SE2, 5U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_Lambda, 6U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_Vlth, 7U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_Vdth, 8U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 9U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 10U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_timer, 11U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_Vxt, 12U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_t0, 13U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_Vxt0_1, 14U, c17_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_y, 15U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_t1, 16U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_Vxt0, 17U, c17_sf_marshallOut,
    c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c17_tau_1_address, 18U,
    c17_sf_marshallOut, c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c17_current_period_1_address, 19U, c17_sf_marshallOut,
     c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c17_period_index_1_address,
    20U, c17_sf_marshallOut, c17_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c17_last_adaptation_1_address, 21U, c17_sf_marshallOut,
     c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 8);
  c17_t1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 9);
  for (c17_i0 = 0; c17_i0 < 4; c17_i0++) {
    c17_candidate_period[c17_i0] = c17_dv0[c17_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 10);
  c17_no_of_candidates = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 11);
  c17_alpha_1 = -31.4772;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 12);
  c17_alpha_2 = 3.7059;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 13);
  c17_beta = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 14);
  c17_X_SE2 = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 15);
  c17_Lambda = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 16);
  c17_Vlth = -3.14772;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 17);
  c17_Vdth = -3.14772;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 19);
  c17_e_hoistedGlobal = c17_get_tau_1(chartInstance, 0);
  c17_u = c17_e_hoistedGlobal;
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c17_b_y);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 20);
  c17_b_u = c17_Vxt;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c17_c_y);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 21);
  c17_c_u = c17_Vdth;
  c17_d_y = NULL;
  sf_mex_assign(&c17_d_y, sf_mex_create("y", &c17_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c17_d_y);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 22);
  c17_d_u = c17_Vlth;
  c17_e_y = NULL;
  sf_mex_assign(&c17_e_y, sf_mex_create("y", &c17_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c17_e_y);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 23);
  if (CV_EML_IF(0, 1, 0, c17_Vxt < c17_Vdth)) {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 24);
    c17_set_tau_1(chartInstance, 0, c17_get_tau_1(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 25);
    if (CV_EML_IF(0, 1, 1, c17_get_tau_1(chartInstance, 0) == 100.0)) {
      _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 26);
      if (CV_EML_IF(0, 1, 2, c17_get_current_period_1(chartInstance, 0) <
                    c17_candidate_period[2])) {
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 27);
        c17_set_current_period_1(chartInstance, 0, c17_candidate_period[(int32_T)
                                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "candidate_period", (int32_T)_SFD_INTEGER_CHECK("period_index_1 + 1",
          c17_get_period_index_1(chartInstance, 0) + 1.0), 1, 4, 1, 0) - 1]);
        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 28);
        c17_set_period_index_1(chartInstance, 0, c17_get_period_index_1
          (chartInstance, 0) + 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 2);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 29);
        c17_set_last_adaptation_1(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 1);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 31);
        c17_set_tau_1(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 3);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 32);
        c17_t1 = c17_t0;
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 33);
        for (c17_i1 = 0; c17_i1 < 5; c17_i1++) {
          c17_e_u[c17_i1] = c17_cv0[c17_i1];
        }

        c17_f_y = NULL;
        sf_mex_assign(&c17_f_y, sf_mex_create("y", c17_e_u, 10, 0U, 1U, 0U, 2, 1,
          5), FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c17_f_y);
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 36);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c17_Vxt > c17_Vlth)) {
      if (CV_EML_COND(0, 1, 1, c17_get_current_period_1(chartInstance, 0) >
                      c17_candidate_period[0])) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 37);
        for (c17_i2 = 0; c17_i2 < 20; c17_i2++) {
          c17_f_u[c17_i2] = c17_cv1[c17_i2];
        }

        c17_g_y = NULL;
        sf_mex_assign(&c17_g_y, sf_mex_create("y", c17_f_u, 10, 0U, 1U, 0U, 2, 1,
          20), FALSE);
        sf_mex_call_debug("disp", 0U, 1U, 14, c17_g_y);
        _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 38);
        if (CV_EML_IF(0, 1, 4, c17_get_last_adaptation_1(chartInstance, 0) ==
                      1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 40);
          for (c17_i3 = 0; c17_i3 < 11; c17_i3++) {
            c17_g_u[c17_i3] = c17_cv2[c17_i3];
          }

          c17_h_y = NULL;
          sf_mex_assign(&c17_h_y, sf_mex_create("y", c17_g_u, 10, 0U, 1U, 0U, 2,
            1, 11), FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c17_h_y);
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 41);
          c17_set_current_period_1(chartInstance, 0, c17_candidate_period
            [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period",
            (int32_T)_SFD_INTEGER_CHECK("period_index_1 - 1",
            c17_get_period_index_1(chartInstance, 0) - 1.0), 1, 4, 1, 0) - 1]);
          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 42);
          c17_set_period_index_1(chartInstance, 0, c17_get_period_index_1
            (chartInstance, 0) - 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 2);
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 43);
          c17_set_last_adaptation_1(chartInstance, 0, -1.0);
          ssUpdateDataStoreLog(chartInstance->S, 1);
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 45);
          c17_set_tau_1(chartInstance, 0, 0.0);
          ssUpdateDataStoreLog(chartInstance->S, 3);
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 46);
          c17_t1 = c17_timer;
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 47);
          c17_Vxt0_1 = c17_Vxt;
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 48);
          for (c17_i4 = 0; c17_i4 < 2; c17_i4++) {
            c17_h_u[c17_i4] = c17_cv3[c17_i4];
          }

          c17_i_y = NULL;
          sf_mex_assign(&c17_i_y, sf_mex_create("y", c17_h_u, 10, 0U, 1U, 0U, 2,
            1, 2), FALSE);
          sf_mex_call_debug("disp", 0U, 1U, 14, c17_i_y);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 49);
          guard2 = FALSE;
          if (CV_EML_COND(0, 1, 2, c17_get_last_adaptation_1(chartInstance, 0) ==
                          -1.0)) {
            c17_b = c17_timer - c17_t0;
            c17_b_b = c17_b;
            c17_c_b = c17_b_b;
            c17_eml_scalar_eg(chartInstance);
            c17_bk = c17_c_b;
            c17_d_b = c17_bk;
            c17_eml_scalar_eg(chartInstance);
            c17_br = c17_d_b;
            c17_c = muDoubleScalarPower(0.73016001511103923, c17_br);
            c17_a = c17_c;
            c17_e_b = c17_Vxt0_1;
            c17_j_y = c17_a * c17_e_b;
            if (CV_EML_COND(0, 1, 3, c17_Vxt > c17_j_y)) {
              CV_EML_MCDC(0, 1, 1, TRUE);
              CV_EML_IF(0, 1, 5, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 51);
              c17_set_current_period_1(chartInstance, 0, c17_candidate_period
                [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period",
                                        (int32_T)_SFD_INTEGER_CHECK(
                "period_index_1 - 1", c17_get_period_index_1(chartInstance, 0) -
                1.0), 1, 4, 1, 0) - 1]);
              ssUpdateDataStoreLog(chartInstance->S, 0);
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 52);
              c17_set_period_index_1(chartInstance, 0, c17_get_period_index_1
                (chartInstance, 0) - 1.0);
              ssUpdateDataStoreLog(chartInstance->S, 2);
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 53);
              c17_set_last_adaptation_1(chartInstance, 0, -1.0);
              ssUpdateDataStoreLog(chartInstance->S, 1);
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 55);
              c17_t1 = c17_timer;
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 56);
              c17_set_tau_1(chartInstance, 0, 0.0);
              ssUpdateDataStoreLog(chartInstance->S, 3);
              _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 57);
              for (c17_i5 = 0; c17_i5 < 3; c17_i5++) {
                c17_i_u[c17_i5] = c17_cv4[c17_i5];
              }

              c17_k_y = NULL;
              sf_mex_assign(&c17_k_y, sf_mex_create("y", c17_i_u, 10, 0U, 1U, 0U,
                2, 1, 3), FALSE);
              sf_mex_call_debug("disp", 0U, 1U, 14, c17_k_y);
            } else {
              guard2 = TRUE;
            }
          } else {
            guard2 = TRUE;
          }

          if (guard2 == TRUE) {
            CV_EML_MCDC(0, 1, 1, FALSE);
            CV_EML_IF(0, 1, 5, FALSE);
          }
        }
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      CV_EML_MCDC(0, 1, 0, FALSE);
      CV_EML_IF(0, 1, 3, FALSE);
      _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 60);
      c17_set_current_period_1(chartInstance, 0, c17_candidate_period[(int32_T)
        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period", (int32_T)
        _SFD_INTEGER_CHECK("period_index_1", c17_get_period_index_1
                           (chartInstance, 0)), 1, 4, 1, 0) - 1]);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 62);
      c17_set_tau_1(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 63);
      c17_t1 = c17_timer;
      _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 64);
      for (c17_i6 = 0; c17_i6 < 4; c17_i6++) {
        c17_j_u[c17_i6] = c17_cv5[c17_i6];
      }

      c17_l_y = NULL;
      sf_mex_assign(&c17_l_y, sf_mex_create("y", c17_j_u, 10, 0U, 1U, 0U, 2, 1,
        4), FALSE);
      sf_mex_call_debug("disp", 0U, 1U, 14, c17_l_y);
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 67);
  c17_k_u = c17_Vxt0_1;
  c17_m_y = NULL;
  sf_mex_assign(&c17_m_y, sf_mex_create("y", &c17_k_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_call_debug("disp", 0U, 1U, 14, c17_m_y);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 68);
  c17_y = c17_get_current_period_1(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 70);
  c17_Vxt0 = c17_Vxt0_1;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -70);
  _SFD_SYMBOL_SCOPE_POP();
  *c17_n_y = c17_y;
  *c17_b_t1 = c17_t1;
  *c17_b_Vxt0 = c17_Vxt0;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
}

static void initSimStructsc17_Control_Loop4_2Model
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber)
{
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static real_T c17_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_last_adaptation_1, const char_T
  *c17_identifier)
{
  real_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_last_adaptation_1),
    &c17_thisId);
  sf_mex_destroy(&c17_last_adaptation_1);
  return c17_y;
}

static real_T c17_b_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_last_adaptation_1;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_last_adaptation_1 = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_last_adaptation_1),
    &c17_thisId);
  sf_mex_destroy(&c17_last_adaptation_1);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i7;
  real_T c17_b_inData[4];
  int32_T c17_i8;
  real_T c17_u[4];
  const mxArray *c17_y = NULL;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i7 = 0; c17_i7 < 4; c17_i7++) {
    c17_b_inData[c17_i7] = (*(real_T (*)[4])c17_inData)[c17_i7];
  }

  for (c17_i8 = 0; c17_i8 < 4; c17_i8++) {
    c17_u[c17_i8] = c17_b_inData[c17_i8];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static void c17_c_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[4])
{
  real_T c17_dv1[4];
  int32_T c17_i9;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c17_i9 = 0; c17_i9 < 4; c17_i9++) {
    c17_y[c17_i9] = c17_dv1[c17_i9];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_candidate_period;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[4];
  int32_T c17_i10;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_candidate_period = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_candidate_period),
    &c17_thisId, c17_y);
  sf_mex_destroy(&c17_candidate_period);
  for (c17_i10 = 0; c17_i10 < 4; c17_i10++) {
    (*(real_T (*)[4])c17_outData)[c17_i10] = c17_y[c17_i10];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 21, 1),
                FALSE);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  const mxArray *c17_rhs3 = NULL;
  const mxArray *c17_lhs3 = NULL;
  const mxArray *c17_rhs4 = NULL;
  const mxArray *c17_lhs4 = NULL;
  const mxArray *c17_rhs5 = NULL;
  const mxArray *c17_lhs5 = NULL;
  const mxArray *c17_rhs6 = NULL;
  const mxArray *c17_lhs6 = NULL;
  const mxArray *c17_rhs7 = NULL;
  const mxArray *c17_lhs7 = NULL;
  const mxArray *c17_rhs8 = NULL;
  const mxArray *c17_lhs8 = NULL;
  const mxArray *c17_rhs9 = NULL;
  const mxArray *c17_lhs9 = NULL;
  const mxArray *c17_rhs10 = NULL;
  const mxArray *c17_lhs10 = NULL;
  const mxArray *c17_rhs11 = NULL;
  const mxArray *c17_lhs11 = NULL;
  const mxArray *c17_rhs12 = NULL;
  const mxArray *c17_lhs12 = NULL;
  const mxArray *c17_rhs13 = NULL;
  const mxArray *c17_lhs13 = NULL;
  const mxArray *c17_rhs14 = NULL;
  const mxArray *c17_lhs14 = NULL;
  const mxArray *c17_rhs15 = NULL;
  const mxArray *c17_lhs15 = NULL;
  const mxArray *c17_rhs16 = NULL;
  const mxArray *c17_lhs16 = NULL;
  const mxArray *c17_rhs17 = NULL;
  const mxArray *c17_lhs17 = NULL;
  const mxArray *c17_rhs18 = NULL;
  const mxArray *c17_lhs18 = NULL;
  const mxArray *c17_rhs19 = NULL;
  const mxArray *c17_lhs19 = NULL;
  const mxArray *c17_rhs20 = NULL;
  const mxArray *c17_lhs20 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("disp"), "name", "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("disp"), "name", "name", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXMB]$matlabroot$/toolbox/matlab/lang/disp"), "resolved", "resolved", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeLo", "mFileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(MAX_uint32_T),
                  "mFileTimeHi", "mFileTimeHi", 3);
  sf_mex_assign(&c17_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("mrdivide"), "name", "name",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1373284908U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1319708366U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c17_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("rdivide"), "name", "name", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c17_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c17_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c17_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_div"), "name", "name", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688666U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c17_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("mpower"), "name", "name", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c17_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c17_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("ismatrix"), "name", "name",
                  11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c17_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("power"), "name", "name", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c17_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c17_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c17_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1358160940U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c17_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("floor"), "name", "name", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c17_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c17_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c17_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_error"), "name", "name",
                  19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c17_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c17_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c17_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs20), "lhs", "lhs",
                  20);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
  sf_mex_destroy(&c17_rhs3);
  sf_mex_destroy(&c17_lhs3);
  sf_mex_destroy(&c17_rhs4);
  sf_mex_destroy(&c17_lhs4);
  sf_mex_destroy(&c17_rhs5);
  sf_mex_destroy(&c17_lhs5);
  sf_mex_destroy(&c17_rhs6);
  sf_mex_destroy(&c17_lhs6);
  sf_mex_destroy(&c17_rhs7);
  sf_mex_destroy(&c17_lhs7);
  sf_mex_destroy(&c17_rhs8);
  sf_mex_destroy(&c17_lhs8);
  sf_mex_destroy(&c17_rhs9);
  sf_mex_destroy(&c17_lhs9);
  sf_mex_destroy(&c17_rhs10);
  sf_mex_destroy(&c17_lhs10);
  sf_mex_destroy(&c17_rhs11);
  sf_mex_destroy(&c17_lhs11);
  sf_mex_destroy(&c17_rhs12);
  sf_mex_destroy(&c17_lhs12);
  sf_mex_destroy(&c17_rhs13);
  sf_mex_destroy(&c17_lhs13);
  sf_mex_destroy(&c17_rhs14);
  sf_mex_destroy(&c17_lhs14);
  sf_mex_destroy(&c17_rhs15);
  sf_mex_destroy(&c17_lhs15);
  sf_mex_destroy(&c17_rhs16);
  sf_mex_destroy(&c17_lhs16);
  sf_mex_destroy(&c17_rhs17);
  sf_mex_destroy(&c17_lhs17);
  sf_mex_destroy(&c17_rhs18);
  sf_mex_destroy(&c17_lhs18);
  sf_mex_destroy(&c17_rhs19);
  sf_mex_destroy(&c17_lhs19);
  sf_mex_destroy(&c17_rhs20);
  sf_mex_destroy(&c17_lhs20);
}

static const mxArray *c17_emlrt_marshallOut(char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), FALSE);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c17_y;
}

static void c17_eml_scalar_eg(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, FALSE);
  return c17_mxArrayOutData;
}

static int32_T c17_d_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i11;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i11, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i11;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_e_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_Control_Loop4_2Model, const
  char_T *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_Control_Loop4_2Model), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_Control_Loop4_2Model);
  return c17_y;
}

static uint8_T c17_f_emlrt_marshallIn(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static real_T c17_get_current_period_1(SFc17_Control_Loop4_2ModelInstanceStruct *
  chartInstance, uint32_T c17_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c17_b);
  if (chartInstance->c17_current_period_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_1\' (#192) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c17_current_period_1_address;
}

static void c17_set_current_period_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c17_b);
  if (chartInstance->c17_current_period_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_1\' (#192) in the initialization routine of the chart.\n");
  }

  *chartInstance->c17_current_period_1_address = c17_c;
}

static real_T *c17_access_current_period_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b)
{
  real_T *c17_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c17_current_period_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_1\' (#192) in the initialization routine of the chart.\n");
  }

  c17_c = chartInstance->c17_current_period_1_address;
  if (c17_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c17_c;
}

static real_T c17_get_last_adaptation_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c17_b);
  if (chartInstance->c17_last_adaptation_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_1\' (#194) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c17_last_adaptation_1_address;
}

static void c17_set_last_adaptation_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c17_b);
  if (chartInstance->c17_last_adaptation_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_1\' (#194) in the initialization routine of the chart.\n");
  }

  *chartInstance->c17_last_adaptation_1_address = c17_c;
}

static real_T *c17_access_last_adaptation_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b)
{
  real_T *c17_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c17_last_adaptation_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_1\' (#194) in the initialization routine of the chart.\n");
  }

  c17_c = chartInstance->c17_last_adaptation_1_address;
  if (c17_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c17_c;
}

static real_T c17_get_period_index_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c17_b);
  if (chartInstance->c17_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#187) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c17_period_index_1_address;
}

static void c17_set_period_index_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c17_b);
  if (chartInstance->c17_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#187) in the initialization routine of the chart.\n");
  }

  *chartInstance->c17_period_index_1_address = c17_c;
}

static real_T *c17_access_period_index_1
  (SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c17_b)
{
  real_T *c17_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c17_period_index_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_1\' (#187) in the initialization routine of the chart.\n");
  }

  c17_c = chartInstance->c17_period_index_1_address;
  if (c17_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c17_c;
}

static real_T c17_get_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c17_b);
  if (chartInstance->c17_tau_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_1\' (#193) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c17_tau_1_address;
}

static void c17_set_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b, real_T c17_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c17_b);
  if (chartInstance->c17_tau_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_1\' (#193) in the initialization routine of the chart.\n");
  }

  *chartInstance->c17_tau_1_address = c17_c;
}

static real_T *c17_access_tau_1(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c17_b)
{
  real_T *c17_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c17_tau_1_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_1\' (#193) in the initialization routine of the chart.\n");
  }

  c17_c = chartInstance->c17_tau_1_address;
  if (c17_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c17_c;
}

static void init_dsm_address_info(SFc17_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "current_period_1", (void **)
    &chartInstance->c17_current_period_1_address,
    &chartInstance->c17_current_period_1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "last_adaptation_1", (void **)
    &chartInstance->c17_last_adaptation_1_address,
    &chartInstance->c17_last_adaptation_1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_1", (void **)
    &chartInstance->c17_period_index_1_address,
    &chartInstance->c17_period_index_1_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "tau_1", (void **)
    &chartInstance->c17_tau_1_address, &chartInstance->c17_tau_1_index);
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

void sf_c17_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(929345742U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1715560700U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3155073672U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2477893476U);
}

mxArray *sf_c17_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ouUXfcEtVoBWR5ZbZyCHuB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c17_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[44],T\"Vxt0\",},{M[1],M[42],T\"t1\",},{M[1],M[21],T\"y\",},{M[8],M[0],T\"is_active_c17_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           17,
           1,
           1,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"timer");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Vxt");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,11,0,0,"period_index_1");
          _SFD_SET_DATA_PROPS(4,1,1,0,"t0");
          _SFD_SET_DATA_PROPS(5,2,0,1,"t1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Vxt0_1");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Vxt0");
          _SFD_SET_DATA_PROPS(8,11,0,0,"current_period_1");
          _SFD_SET_DATA_PROPS(9,11,0,0,"tau_1");
          _SFD_SET_DATA_PROPS(10,11,0,0,"last_adaptation_1");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1853);
        _SFD_CV_INIT_EML_IF(0,1,0,379,394,776,1738);
        _SFD_CV_INIT_EML_IF(0,1,1,423,440,-1,775);
        _SFD_CV_INIT_EML_IF(0,1,2,449,507,-1,767);
        _SFD_CV_INIT_EML_IF(0,1,3,776,841,1596,1738);
        _SFD_CV_INIT_EML_IF(0,1,4,880,907,1204,1290);
        _SFD_CV_INIT_EML_IF(0,1,5,1204,1290,-1,1290);

        {
          static int condStart[] = { 785, 801 };

          static int condEnd[] = { 795, 839 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,784,840,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1213, 1242 };

          static int condEnd[] = { 1236, 1288 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1212,1289,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)c17_sf_marshallIn);

        {
          real_T *c17_timer;
          real_T *c17_Vxt;
          real_T *c17_y;
          real_T *c17_t0;
          real_T *c17_t1;
          real_T *c17_Vxt0_1;
          real_T *c17_Vxt0;
          c17_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c17_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c17_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c17_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c17_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c17_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c17_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c17_timer);
          _SFD_SET_DATA_VALUE_PTR(1U, c17_Vxt);
          _SFD_SET_DATA_VALUE_PTR(2U, c17_y);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c17_period_index_1_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c17_t0);
          _SFD_SET_DATA_VALUE_PTR(5U, c17_t1);
          _SFD_SET_DATA_VALUE_PTR(6U, c17_Vxt0_1);
          _SFD_SET_DATA_VALUE_PTR(7U, c17_Vxt0);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c17_current_period_1_address);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c17_tau_1_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c17_last_adaptation_1_address);
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
  return "FBYoiBDKbgvWSjOcGRL8AH";
}

static void sf_opaque_initialize_c17_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_Control_Loop4_2Model
    ((SFc17_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c17_Control_Loop4_2Model((SFc17_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c17_Control_Loop4_2Model((SFc17_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c17_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c17_Control_Loop4_2Model((SFc17_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c17_Control_Loop4_2Model((SFc17_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_Control_Loop4_2Model
    ((SFc17_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_Control_Loop4_2Model();/* state var info */
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

extern void sf_internal_set_sim_state_c17_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_Control_Loop4_2Model
    ((SFc17_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c17_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c17_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c17_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c17_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c17_Control_Loop4_2Model((SFc17_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_Control_Loop4_2Model
    ((SFc17_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c17_Control_Loop4_2Model
      ((SFc17_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,17,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1356819348U));
  ssSetChecksum1(S,(3445557673U));
  ssSetChecksum2(S,(2919712413U));
  ssSetChecksum3(S,(4149573286U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c17_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_Control_Loop4_2Model(SimStruct *S)
{
  SFc17_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc17_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc17_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_Control_Loop4_2Model;
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

void c17_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
