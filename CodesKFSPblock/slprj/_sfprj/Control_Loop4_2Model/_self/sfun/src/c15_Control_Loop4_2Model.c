/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c15_Control_Loop4_2Model.h"
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
static const char * c15_debug_family_names[22] = { "candidate_period",
  "no_of_candidates", "alpha_1", "alpha_2", "beta", "X_SE2", "Lambda", "Vlth",
  "Vdth", "nargin", "nargout", "timer", "Vxt", "t0", "Vxt0_1", "y", "t1", "Vxt0",
  "tau_2", "current_period_2", "period_index_2", "last_adaptation_2" };

/* Function Declarations */
static void initialize_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c15_update_debugger_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c15_st);
static void finalize_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c15_Control_Loop4_2Model(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c15_chartstep_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initSimStructsc15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber);
static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static real_T c15_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_last_adaptation_2, const char_T
  *c15_identifier);
static real_T c15_b_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static void c15_c_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3]);
static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static void c15_info_helper(const mxArray **c15_info);
static const mxArray *c15_emlrt_marshallOut(char * c15_u);
static const mxArray *c15_b_emlrt_marshallOut(uint32_T c15_u);
static void c15_eml_scalar_eg(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData);
static int32_T c15_d_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData);
static uint8_T c15_e_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Control_Loop4_2Model, const
  char_T *c15_identifier);
static uint8_T c15_f_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId);
static real_T c15_get_current_period_2(SFc15_Control_Loop4_2ModelInstanceStruct *
  chartInstance, uint32_T c15_b);
static void c15_set_current_period_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c);
static real_T *c15_access_current_period_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b);
static real_T c15_get_last_adaptation_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b);
static void c15_set_last_adaptation_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c);
static real_T *c15_access_last_adaptation_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b);
static real_T c15_get_period_index_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b);
static void c15_set_period_index_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c);
static real_T *c15_access_period_index_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b);
static real_T c15_get_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b);
static void c15_set_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c);
static real_T *c15_access_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b);
static void init_dsm_address_info(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c15_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c15_is_active_c15_Control_Loop4_2Model = 0U;
}

static void initialize_params_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c15_update_debugger_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c15_st;
  const mxArray *c15_y = NULL;
  real_T c15_hoistedGlobal;
  real_T c15_u;
  const mxArray *c15_b_y = NULL;
  real_T c15_b_hoistedGlobal;
  real_T c15_b_u;
  const mxArray *c15_c_y = NULL;
  real_T c15_c_hoistedGlobal;
  real_T c15_c_u;
  const mxArray *c15_d_y = NULL;
  uint8_T c15_d_hoistedGlobal;
  uint8_T c15_d_u;
  const mxArray *c15_e_y = NULL;
  real_T *c15_Vxt0;
  real_T *c15_t1;
  real_T *c15_f_y;
  c15_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_f_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_st = NULL;
  c15_st = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_createcellarray(4), FALSE);
  c15_hoistedGlobal = *c15_Vxt0;
  c15_u = c15_hoistedGlobal;
  c15_b_y = NULL;
  sf_mex_assign(&c15_b_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 0, c15_b_y);
  c15_b_hoistedGlobal = *c15_t1;
  c15_b_u = c15_b_hoistedGlobal;
  c15_c_y = NULL;
  sf_mex_assign(&c15_c_y, sf_mex_create("y", &c15_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 1, c15_c_y);
  c15_c_hoistedGlobal = *c15_f_y;
  c15_c_u = c15_c_hoistedGlobal;
  c15_d_y = NULL;
  sf_mex_assign(&c15_d_y, sf_mex_create("y", &c15_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 2, c15_d_y);
  c15_d_hoistedGlobal = chartInstance->c15_is_active_c15_Control_Loop4_2Model;
  c15_d_u = c15_d_hoistedGlobal;
  c15_e_y = NULL;
  sf_mex_assign(&c15_e_y, sf_mex_create("y", &c15_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c15_y, 3, c15_e_y);
  sf_mex_assign(&c15_st, c15_y, FALSE);
  return c15_st;
}

static void set_sim_state_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c15_st)
{
  const mxArray *c15_u;
  real_T *c15_Vxt0;
  real_T *c15_t1;
  real_T *c15_y;
  c15_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c15_doneDoubleBufferReInit = TRUE;
  c15_u = sf_mex_dup(c15_st);
  *c15_Vxt0 = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c15_u, 0)), "Vxt0");
  *c15_t1 = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    1)), "t1");
  *c15_y = c15_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c15_u,
    2)), "y");
  chartInstance->c15_is_active_c15_Control_Loop4_2Model = c15_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c15_u, 3)),
     "is_active_c15_Control_Loop4_2Model");
  sf_mex_destroy(&c15_u);
  c15_update_debugger_state_c15_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c15_st);
}

static void finalize_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c15_Control_Loop4_2Model(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  real_T *c15_timer;
  real_T *c15_Vxt;
  real_T *c15_y;
  real_T *c15_t0;
  real_T *c15_t1;
  real_T *c15_Vxt0_1;
  real_T *c15_Vxt0;
  c15_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c15_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c15_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c15_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c15_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c15_timer, 0U);
  _SFD_DATA_RANGE_CHECK(*c15_Vxt, 1U);
  _SFD_DATA_RANGE_CHECK(*c15_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c15_t0, 4U);
  _SFD_DATA_RANGE_CHECK(*c15_t1, 5U);
  _SFD_DATA_RANGE_CHECK(*c15_Vxt0_1, 6U);
  _SFD_DATA_RANGE_CHECK(*c15_Vxt0, 7U);
  chartInstance->c15_sfEvent = CALL_EVENT;
  c15_chartstep_c15_Control_Loop4_2Model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c15_chartstep_c15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  real_T c15_hoistedGlobal;
  real_T c15_b_hoistedGlobal;
  real_T c15_c_hoistedGlobal;
  real_T c15_d_hoistedGlobal;
  real_T c15_timer;
  real_T c15_Vxt;
  real_T c15_t0;
  real_T c15_Vxt0_1;
  uint32_T c15_debug_family_var_map[22];
  real_T c15_candidate_period[3];
  real_T c15_no_of_candidates;
  real_T c15_alpha_1;
  real_T c15_alpha_2;
  real_T c15_beta;
  real_T c15_X_SE2;
  real_T c15_Lambda;
  real_T c15_Vlth;
  real_T c15_Vdth;
  real_T c15_nargin = 4.0;
  real_T c15_nargout = 3.0;
  real_T c15_y;
  real_T c15_t1;
  real_T c15_Vxt0;
  int32_T c15_i0;
  static real_T c15_dv0[3] = { 10.0, 20.0, 60.0 };

  real_T c15_b;
  real_T c15_b_b;
  real_T c15_c_b;
  real_T c15_bk;
  real_T c15_d_b;
  real_T c15_br;
  real_T c15_c;
  real_T c15_a;
  real_T c15_e_b;
  real_T c15_b_y;
  real_T *c15_b_Vxt0;
  real_T *c15_b_t1;
  real_T *c15_c_y;
  real_T *c15_b_Vxt0_1;
  real_T *c15_b_t0;
  real_T *c15_b_Vxt;
  real_T *c15_b_timer;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c15_b_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c15_b_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c15_b_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c15_b_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c15_c_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c15_b_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c15_b_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c15_sfEvent);
  c15_hoistedGlobal = *c15_b_timer;
  c15_b_hoistedGlobal = *c15_b_Vxt;
  c15_c_hoistedGlobal = *c15_b_t0;
  c15_d_hoistedGlobal = *c15_b_Vxt0_1;
  c15_timer = c15_hoistedGlobal;
  c15_Vxt = c15_b_hoistedGlobal;
  c15_t0 = c15_c_hoistedGlobal;
  c15_Vxt0_1 = c15_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c15_debug_family_names,
    c15_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c15_candidate_period, 0U,
    c15_b_sf_marshallOut, c15_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_no_of_candidates, 1U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_alpha_1, 2U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_alpha_2, 3U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_beta, 4U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_X_SE2, 5U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Lambda, 6U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Vlth, 7U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Vdth, 8U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargin, 9U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_nargout, 10U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_timer, 11U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Vxt, 12U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_t0, 13U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c15_Vxt0_1, 14U, c15_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_y, 15U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_t1, 16U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c15_Vxt0, 17U, c15_sf_marshallOut,
    c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_tau_2_address, 18U,
    c15_sf_marshallOut, c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c15_current_period_2_address, 19U, c15_sf_marshallOut,
     c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c15_period_index_2_address,
    20U, c15_sf_marshallOut, c15_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE
    (chartInstance->c15_last_adaptation_2_address, 21U, c15_sf_marshallOut,
     c15_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 8);
  c15_t1 = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 9);
  for (c15_i0 = 0; c15_i0 < 3; c15_i0++) {
    c15_candidate_period[c15_i0] = c15_dv0[c15_i0];
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 10);
  c15_no_of_candidates = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 11);
  c15_alpha_1 = -31.4772;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 12);
  c15_alpha_2 = 3.7059;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 13);
  c15_beta = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 14);
  c15_X_SE2 = 0.01;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 15);
  c15_Lambda = 0.1;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 16);
  c15_Vlth = -0.314772;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 17);
  c15_Vdth = -0.031477200000000004;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 21);
  if (CV_EML_IF(0, 1, 0, c15_Vxt < c15_Vdth)) {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 22);
    c15_set_tau_2(chartInstance, 0, c15_get_tau_2(chartInstance, 0) + 1.0);
    ssUpdateDataStoreLog(chartInstance->S, 3);
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 24);
    if (CV_EML_IF(0, 1, 1, c15_get_tau_2(chartInstance, 0) == 100.0)) {
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 25);
      if (CV_EML_IF(0, 1, 2, c15_get_current_period_2(chartInstance, 0) <
                    c15_candidate_period[2])) {
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 26);
        c15_set_current_period_2(chartInstance, 0, c15_candidate_period[(int32_T)
                                 (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
          "candidate_period", (int32_T)_SFD_INTEGER_CHECK("period_index_2 + 1",
          c15_get_period_index_2(chartInstance, 0) + 1.0), 1, 3, 1, 0) - 1]);
        ssUpdateDataStoreLog(chartInstance->S, 0);
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 27);
        c15_set_period_index_2(chartInstance, 0, c15_get_period_index_2
          (chartInstance, 0) + 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 2);
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 28);
        c15_set_last_adaptation_2(chartInstance, 0, 1.0);
        ssUpdateDataStoreLog(chartInstance->S, 1);
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 29);
        c15_set_tau_2(chartInstance, 0, 0.0);
        ssUpdateDataStoreLog(chartInstance->S, 3);
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 30);
        c15_t1 = c15_t0;
      }
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 34);
    guard1 = FALSE;
    if (CV_EML_COND(0, 1, 0, c15_Vxt > c15_Vlth)) {
      if (CV_EML_COND(0, 1, 1, c15_get_current_period_2(chartInstance, 0) >
                      c15_candidate_period[0])) {
        CV_EML_MCDC(0, 1, 0, TRUE);
        CV_EML_IF(0, 1, 3, TRUE);
        _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 35);
        if (CV_EML_IF(0, 1, 4, c15_get_last_adaptation_2(chartInstance, 0) ==
                      1.0)) {
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 36);
          c15_set_current_period_2(chartInstance, 0, c15_candidate_period
            [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period",
            (int32_T)_SFD_INTEGER_CHECK("period_index_2 - 1",
            c15_get_period_index_2(chartInstance, 0) - 1.0), 1, 3, 1, 0) - 1]);
          ssUpdateDataStoreLog(chartInstance->S, 0);
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 37);
          c15_set_period_index_2(chartInstance, 0, c15_get_period_index_2
            (chartInstance, 0) - 1.0);
          ssUpdateDataStoreLog(chartInstance->S, 2);
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 38);
          c15_set_last_adaptation_2(chartInstance, 0, -1.0);
          ssUpdateDataStoreLog(chartInstance->S, 1);
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 39);
          c15_set_tau_2(chartInstance, 0, 0.0);
          ssUpdateDataStoreLog(chartInstance->S, 3);
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 40);
          c15_t1 = c15_timer;
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 41);
          c15_Vxt0_1 = c15_Vxt;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 43);
          guard2 = FALSE;
          if (CV_EML_COND(0, 1, 2, c15_get_last_adaptation_2(chartInstance, 0) ==
                          -1.0)) {
            c15_b = c15_timer - c15_t0;
            c15_b_b = c15_b;
            c15_c_b = c15_b_b;
            c15_eml_scalar_eg(chartInstance);
            c15_bk = c15_c_b;
            c15_d_b = c15_bk;
            c15_eml_scalar_eg(chartInstance);
            c15_br = c15_d_b;
            c15_c = muDoubleScalarPower(0.73016001511103923, c15_br);
            c15_a = c15_c;
            c15_e_b = c15_Vxt0_1;
            c15_b_y = c15_a * c15_e_b;
            if (CV_EML_COND(0, 1, 3, c15_Vxt > c15_b_y)) {
              CV_EML_MCDC(0, 1, 1, TRUE);
              CV_EML_IF(0, 1, 5, TRUE);
              _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 44);
              c15_set_current_period_2(chartInstance, 0, c15_candidate_period
                [(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period",
                                        (int32_T)_SFD_INTEGER_CHECK(
                "period_index_2 - 1", c15_get_period_index_2(chartInstance, 0) -
                1.0), 1, 3, 1, 0) - 1]);
              ssUpdateDataStoreLog(chartInstance->S, 0);
              _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 45);
              c15_set_period_index_2(chartInstance, 0, c15_get_period_index_2
                (chartInstance, 0) - 1.0);
              ssUpdateDataStoreLog(chartInstance->S, 2);
              _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 46);
              c15_set_last_adaptation_2(chartInstance, 0, -1.0);
              ssUpdateDataStoreLog(chartInstance->S, 1);
              _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 47);
              c15_t1 = c15_timer;
              _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 48);
              c15_set_tau_2(chartInstance, 0, 0.0);
              ssUpdateDataStoreLog(chartInstance->S, 3);
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
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 52);
      c15_set_current_period_2(chartInstance, 0, c15_candidate_period[(int32_T)
        (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("candidate_period", (int32_T)
        _SFD_INTEGER_CHECK("period_index_2", c15_get_period_index_2
                           (chartInstance, 0)), 1, 3, 1, 0) - 1]);
      ssUpdateDataStoreLog(chartInstance->S, 0);
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 54);
      c15_set_tau_2(chartInstance, 0, 0.0);
      ssUpdateDataStoreLog(chartInstance->S, 3);
      _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 55);
      c15_t1 = c15_timer;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 59);
  c15_y = c15_get_current_period_2(chartInstance, 0);
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, 61);
  c15_Vxt0 = c15_Vxt0_1;
  _SFD_EML_CALL(0U, chartInstance->c15_sfEvent, -61);
  _SFD_SYMBOL_SCOPE_POP();
  *c15_c_y = c15_y;
  *c15_b_t1 = c15_t1;
  *c15_b_Vxt0 = c15_Vxt0;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c15_sfEvent);
}

static void initSimStructsc15_Control_Loop4_2Model
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c15_machineNumber, uint32_T
  c15_chartNumber)
{
}

static const mxArray *c15_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  real_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(real_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static real_T c15_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_last_adaptation_2, const char_T
  *c15_identifier)
{
  real_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_last_adaptation_2),
    &c15_thisId);
  sf_mex_destroy(&c15_last_adaptation_2);
  return c15_y;
}

static real_T c15_b_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  real_T c15_y;
  real_T c15_d0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_d0, 1, 0, 0U, 0, 0U, 0);
  c15_y = c15_d0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_last_adaptation_2;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_last_adaptation_2 = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_last_adaptation_2),
    &c15_thisId);
  sf_mex_destroy(&c15_last_adaptation_2);
  *(real_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static const mxArray *c15_b_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_i1;
  real_T c15_b_inData[3];
  int32_T c15_i2;
  real_T c15_u[3];
  const mxArray *c15_y = NULL;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  for (c15_i1 = 0; c15_i1 < 3; c15_i1++) {
    c15_b_inData[c15_i1] = (*(real_T (*)[3])c15_inData)[c15_i1];
  }

  for (c15_i2 = 0; c15_i2 < 3; c15_i2++) {
    c15_u[c15_i2] = c15_b_inData[c15_i2];
  }

  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static void c15_c_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId,
  real_T c15_y[3])
{
  real_T c15_dv1[3];
  int32_T c15_i3;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), c15_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                3);
  for (c15_i3 = 0; c15_i3 < 3; c15_i3++) {
    c15_y[c15_i3] = c15_dv1[c15_i3];
  }

  sf_mex_destroy(&c15_u);
}

static void c15_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_candidate_period;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  real_T c15_y[3];
  int32_T c15_i4;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_candidate_period = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_candidate_period),
    &c15_thisId, c15_y);
  sf_mex_destroy(&c15_candidate_period);
  for (c15_i4 = 0; c15_i4 < 3; c15_i4++) {
    (*(real_T (*)[3])c15_outData)[c15_i4] = c15_y[c15_i4];
  }

  sf_mex_destroy(&c15_mxArrayInData);
}

const mxArray *sf_c15_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c15_nameCaptureInfo = NULL;
  c15_nameCaptureInfo = NULL;
  sf_mex_assign(&c15_nameCaptureInfo, sf_mex_createstruct("structure", 2, 19, 1),
                FALSE);
  c15_info_helper(&c15_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c15_nameCaptureInfo);
  return c15_nameCaptureInfo;
}

static void c15_info_helper(const mxArray **c15_info)
{
  const mxArray *c15_rhs0 = NULL;
  const mxArray *c15_lhs0 = NULL;
  const mxArray *c15_rhs1 = NULL;
  const mxArray *c15_lhs1 = NULL;
  const mxArray *c15_rhs2 = NULL;
  const mxArray *c15_lhs2 = NULL;
  const mxArray *c15_rhs3 = NULL;
  const mxArray *c15_lhs3 = NULL;
  const mxArray *c15_rhs4 = NULL;
  const mxArray *c15_lhs4 = NULL;
  const mxArray *c15_rhs5 = NULL;
  const mxArray *c15_lhs5 = NULL;
  const mxArray *c15_rhs6 = NULL;
  const mxArray *c15_lhs6 = NULL;
  const mxArray *c15_rhs7 = NULL;
  const mxArray *c15_lhs7 = NULL;
  const mxArray *c15_rhs8 = NULL;
  const mxArray *c15_lhs8 = NULL;
  const mxArray *c15_rhs9 = NULL;
  const mxArray *c15_lhs9 = NULL;
  const mxArray *c15_rhs10 = NULL;
  const mxArray *c15_lhs10 = NULL;
  const mxArray *c15_rhs11 = NULL;
  const mxArray *c15_lhs11 = NULL;
  const mxArray *c15_rhs12 = NULL;
  const mxArray *c15_lhs12 = NULL;
  const mxArray *c15_rhs13 = NULL;
  const mxArray *c15_lhs13 = NULL;
  const mxArray *c15_rhs14 = NULL;
  const mxArray *c15_lhs14 = NULL;
  const mxArray *c15_rhs15 = NULL;
  const mxArray *c15_lhs15 = NULL;
  const mxArray *c15_rhs16 = NULL;
  const mxArray *c15_lhs16 = NULL;
  const mxArray *c15_rhs17 = NULL;
  const mxArray *c15_lhs17 = NULL;
  const mxArray *c15_rhs18 = NULL;
  const mxArray *c15_lhs18 = NULL;
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mtimes"), "name", "name", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c15_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c15_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1373284908U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1319708366U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c15_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c15_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c15_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c15_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688666U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c15_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("mpower"), "name", "name", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c15_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c15_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("ismatrix"), "name", "name",
                  9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1331279658U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c15_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("power"), "name", "name", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c15_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c15_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c15_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1358160940U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c15_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("floor"), "name", "name", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363688654U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c15_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c15_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797126U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c15_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_error"), "name", "name",
                  17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1343808758U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c15_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c15_info, c15_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c15_info, c15_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c15_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c15_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c15_info, sf_mex_duplicatearraysafe(&c15_lhs18), "lhs", "lhs",
                  18);
  sf_mex_destroy(&c15_rhs0);
  sf_mex_destroy(&c15_lhs0);
  sf_mex_destroy(&c15_rhs1);
  sf_mex_destroy(&c15_lhs1);
  sf_mex_destroy(&c15_rhs2);
  sf_mex_destroy(&c15_lhs2);
  sf_mex_destroy(&c15_rhs3);
  sf_mex_destroy(&c15_lhs3);
  sf_mex_destroy(&c15_rhs4);
  sf_mex_destroy(&c15_lhs4);
  sf_mex_destroy(&c15_rhs5);
  sf_mex_destroy(&c15_lhs5);
  sf_mex_destroy(&c15_rhs6);
  sf_mex_destroy(&c15_lhs6);
  sf_mex_destroy(&c15_rhs7);
  sf_mex_destroy(&c15_lhs7);
  sf_mex_destroy(&c15_rhs8);
  sf_mex_destroy(&c15_lhs8);
  sf_mex_destroy(&c15_rhs9);
  sf_mex_destroy(&c15_lhs9);
  sf_mex_destroy(&c15_rhs10);
  sf_mex_destroy(&c15_lhs10);
  sf_mex_destroy(&c15_rhs11);
  sf_mex_destroy(&c15_lhs11);
  sf_mex_destroy(&c15_rhs12);
  sf_mex_destroy(&c15_lhs12);
  sf_mex_destroy(&c15_rhs13);
  sf_mex_destroy(&c15_lhs13);
  sf_mex_destroy(&c15_rhs14);
  sf_mex_destroy(&c15_lhs14);
  sf_mex_destroy(&c15_rhs15);
  sf_mex_destroy(&c15_lhs15);
  sf_mex_destroy(&c15_rhs16);
  sf_mex_destroy(&c15_lhs16);
  sf_mex_destroy(&c15_rhs17);
  sf_mex_destroy(&c15_lhs17);
  sf_mex_destroy(&c15_rhs18);
  sf_mex_destroy(&c15_lhs18);
}

static const mxArray *c15_emlrt_marshallOut(char * c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", c15_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c15_u)), FALSE);
  return c15_y;
}

static const mxArray *c15_b_emlrt_marshallOut(uint32_T c15_u)
{
  const mxArray *c15_y = NULL;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c15_y;
}

static void c15_eml_scalar_eg(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *c15_c_sf_marshallOut(void *chartInstanceVoid, void
  *c15_inData)
{
  const mxArray *c15_mxArrayOutData = NULL;
  int32_T c15_u;
  const mxArray *c15_y = NULL;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_mxArrayOutData = NULL;
  c15_u = *(int32_T *)c15_inData;
  c15_y = NULL;
  sf_mex_assign(&c15_y, sf_mex_create("y", &c15_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c15_mxArrayOutData, c15_y, FALSE);
  return c15_mxArrayOutData;
}

static int32_T c15_d_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  int32_T c15_y;
  int32_T c15_i5;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_i5, 1, 6, 0U, 0, 0U, 0);
  c15_y = c15_i5;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static void c15_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c15_mxArrayInData, const char_T *c15_varName, void *c15_outData)
{
  const mxArray *c15_b_sfEvent;
  const char_T *c15_identifier;
  emlrtMsgIdentifier c15_thisId;
  int32_T c15_y;
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c15_b_sfEvent = sf_mex_dup(c15_mxArrayInData);
  c15_identifier = c15_varName;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c15_b_sfEvent),
    &c15_thisId);
  sf_mex_destroy(&c15_b_sfEvent);
  *(int32_T *)c15_outData = c15_y;
  sf_mex_destroy(&c15_mxArrayInData);
}

static uint8_T c15_e_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_b_is_active_c15_Control_Loop4_2Model, const
  char_T *c15_identifier)
{
  uint8_T c15_y;
  emlrtMsgIdentifier c15_thisId;
  c15_thisId.fIdentifier = c15_identifier;
  c15_thisId.fParent = NULL;
  c15_y = c15_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c15_b_is_active_c15_Control_Loop4_2Model), &c15_thisId);
  sf_mex_destroy(&c15_b_is_active_c15_Control_Loop4_2Model);
  return c15_y;
}

static uint8_T c15_f_emlrt_marshallIn(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c15_u, const emlrtMsgIdentifier *c15_parentId)
{
  uint8_T c15_y;
  uint8_T c15_u0;
  sf_mex_import(c15_parentId, sf_mex_dup(c15_u), &c15_u0, 1, 3, 0U, 0, 0U, 0);
  c15_y = c15_u0;
  sf_mex_destroy(&c15_u);
  return c15_y;
}

static real_T c15_get_current_period_2(SFc15_Control_Loop4_2ModelInstanceStruct *
  chartInstance, uint32_T c15_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c15_b);
  if (chartInstance->c15_current_period_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_2\' (#1074) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c15_current_period_2_address;
}

static void c15_set_current_period_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c15_b);
  if (chartInstance->c15_current_period_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_2\' (#1074) in the initialization routine of the chart.\n");
  }

  *chartInstance->c15_current_period_2_address = c15_c;
}

static real_T *c15_access_current_period_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b)
{
  real_T *c15_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c15_current_period_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'current_period_2\' (#1074) in the initialization routine of the chart.\n");
  }

  c15_c = chartInstance->c15_current_period_2_address;
  if (c15_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c15_c;
}

static real_T c15_get_last_adaptation_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c15_b);
  if (chartInstance->c15_last_adaptation_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_2\' (#1076) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c15_last_adaptation_2_address;
}

static void c15_set_last_adaptation_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c15_b);
  if (chartInstance->c15_last_adaptation_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_2\' (#1076) in the initialization routine of the chart.\n");
  }

  *chartInstance->c15_last_adaptation_2_address = c15_c;
}

static real_T *c15_access_last_adaptation_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b)
{
  real_T *c15_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c15_last_adaptation_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'last_adaptation_2\' (#1076) in the initialization routine of the chart.\n");
  }

  c15_c = chartInstance->c15_last_adaptation_2_address;
  if (c15_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c15_c;
}

static real_T c15_get_period_index_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 2, NULL, c15_b);
  if (chartInstance->c15_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#1069) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c15_period_index_2_address;
}

static void c15_set_period_index_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 2, NULL, c15_b);
  if (chartInstance->c15_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#1069) in the initialization routine of the chart.\n");
  }

  *chartInstance->c15_period_index_2_address = c15_c;
}

static real_T *c15_access_period_index_2
  (SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance, uint32_T c15_b)
{
  real_T *c15_c;
  ssReadFromDataStore(chartInstance->S, 2, NULL);
  if (chartInstance->c15_period_index_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'period_index_2\' (#1069) in the initialization routine of the chart.\n");
  }

  c15_c = chartInstance->c15_period_index_2_address;
  if (c15_b == 0) {
    ssWriteToDataStore(chartInstance->S, 2, NULL);
  }

  return c15_c;
}

static real_T c15_get_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 3, NULL, c15_b);
  if (chartInstance->c15_tau_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_2\' (#1075) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c15_tau_2_address;
}

static void c15_set_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b, real_T c15_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 3, NULL, c15_b);
  if (chartInstance->c15_tau_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_2\' (#1075) in the initialization routine of the chart.\n");
  }

  *chartInstance->c15_tau_2_address = c15_c;
}

static real_T *c15_access_tau_2(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c15_b)
{
  real_T *c15_c;
  ssReadFromDataStore(chartInstance->S, 3, NULL);
  if (chartInstance->c15_tau_2_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'tau_2\' (#1075) in the initialization routine of the chart.\n");
  }

  c15_c = chartInstance->c15_tau_2_address;
  if (c15_b == 0) {
    ssWriteToDataStore(chartInstance->S, 3, NULL);
  }

  return c15_c;
}

static void init_dsm_address_info(SFc15_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "current_period_2", (void **)
    &chartInstance->c15_current_period_2_address,
    &chartInstance->c15_current_period_2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "last_adaptation_2", (void **)
    &chartInstance->c15_last_adaptation_2_address,
    &chartInstance->c15_last_adaptation_2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "period_index_2", (void **)
    &chartInstance->c15_period_index_2_address,
    &chartInstance->c15_period_index_2_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "tau_2", (void **)
    &chartInstance->c15_tau_2_address, &chartInstance->c15_tau_2_index);
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

void sf_c15_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2525471741U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2868514312U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4224463989U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(867797026U);
}

mxArray *sf_c15_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("SRie1tO1RUHrBhP8YsryF");
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

mxArray *sf_c15_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c15_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c15_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[44],T\"Vxt0\",},{M[1],M[42],T\"t1\",},{M[1],M[21],T\"y\",},{M[8],M[0],T\"is_active_c15_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c15_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           15,
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
          _SFD_SET_DATA_PROPS(3,11,0,0,"period_index_2");
          _SFD_SET_DATA_PROPS(4,1,1,0,"t0");
          _SFD_SET_DATA_PROPS(5,2,0,1,"t1");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Vxt0_1");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Vxt0");
          _SFD_SET_DATA_PROPS(8,11,0,0,"current_period_2");
          _SFD_SET_DATA_PROPS(9,11,0,0,"tau_2");
          _SFD_SET_DATA_PROPS(10,11,0,0,"last_adaptation_2");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1590);
        _SFD_CV_INIT_EML_IF(0,1,0,356,371,749,1516);
        _SFD_CV_INIT_EML_IF(0,1,1,418,435,-1,748);
        _SFD_CV_INIT_EML_IF(0,1,2,444,502,-1,740);
        _SFD_CV_INIT_EML_IF(0,1,3,749,814,1373,1516);
        _SFD_CV_INIT_EML_IF(0,1,4,819,846,1075,1161);
        _SFD_CV_INIT_EML_IF(0,1,5,1075,1161,-1,1161);

        {
          static int condStart[] = { 758, 774 };

          static int condEnd[] = { 768, 812 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,757,813,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1084, 1113 };

          static int condEnd[] = { 1107, 1159 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1083,1160,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c15_sf_marshallOut,(MexInFcnForType)c15_sf_marshallIn);

        {
          real_T *c15_timer;
          real_T *c15_Vxt;
          real_T *c15_y;
          real_T *c15_t0;
          real_T *c15_t1;
          real_T *c15_Vxt0_1;
          real_T *c15_Vxt0;
          c15_Vxt0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c15_Vxt0_1 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c15_t1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c15_t0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c15_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c15_Vxt = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c15_timer = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c15_timer);
          _SFD_SET_DATA_VALUE_PTR(1U, c15_Vxt);
          _SFD_SET_DATA_VALUE_PTR(2U, c15_y);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c15_period_index_2_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c15_t0);
          _SFD_SET_DATA_VALUE_PTR(5U, c15_t1);
          _SFD_SET_DATA_VALUE_PTR(6U, c15_Vxt0_1);
          _SFD_SET_DATA_VALUE_PTR(7U, c15_Vxt0);
          _SFD_SET_DATA_VALUE_PTR(8U,
            chartInstance->c15_current_period_2_address);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c15_tau_2_address);
          _SFD_SET_DATA_VALUE_PTR(10U,
            chartInstance->c15_last_adaptation_2_address);
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
  return "CAsfGv9dGrvRvJDxTWOpfC";
}

static void sf_opaque_initialize_c15_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc15_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c15_Control_Loop4_2Model
    ((SFc15_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c15_Control_Loop4_2Model((SFc15_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c15_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c15_Control_Loop4_2Model((SFc15_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c15_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c15_Control_Loop4_2Model((SFc15_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c15_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c15_Control_Loop4_2Model((SFc15_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c15_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c15_Control_Loop4_2Model
    ((SFc15_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_Control_Loop4_2Model();/* state var info */
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

extern void sf_internal_set_sim_state_c15_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c15_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c15_Control_Loop4_2Model
    ((SFc15_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c15_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c15_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c15_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c15_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c15_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc15_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c15_Control_Loop4_2Model((SFc15_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc15_Control_Loop4_2Model
    ((SFc15_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c15_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c15_Control_Loop4_2Model
      ((SFc15_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c15_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      15);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,15,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,15,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,15);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,15,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,15,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,15);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(582674953U));
  ssSetChecksum1(S,(407278388U));
  ssSetChecksum2(S,(2147774154U));
  ssSetChecksum3(S,(1008563880U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c15_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c15_Control_Loop4_2Model(SimStruct *S)
{
  SFc15_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc15_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc15_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc15_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c15_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c15_Control_Loop4_2Model;
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

void c15_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c15_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c15_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c15_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c15_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
