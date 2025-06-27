/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c14_Control_Loop4_2Model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c14_debug_family_names[17] = { "F", "B", "K", "H", "N_r",
  "Q", "K_k", "y_k", "nargin", "nargout", "U", "Y", "X_Est", "Y_Est", "U_Est",
  "X_k_4", "P_k_4" };

/* Function Declarations */
static void initialize_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c14_st);
static void finalize_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c14_Control_Loop4_2Model(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c14_chartstep_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initSimStructsc14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[16]);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_b_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_X_k_4, const char_T *c14_identifier, real_T
  c14_y[4]);
static void c14_c_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[4]);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_d_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_U_Est, const char_T *c14_identifier);
static real_T c14_e_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(uint32_T c14_u);
static void c14_eye(SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance,
                    real_T c14_I[16]);
static void c14_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c14_b_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c14_c_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void c14_d_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_f_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint8_T c14_g_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Control_Loop4_2Model, const
  char_T *c14_identifier);
static uint8_T c14_h_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static real_T c14_get_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b);
static void c14_set_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b, real_T c14_c);
static real_T *c14_access_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b);
static real_T c14_get_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b);
static void c14_set_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b, real_T c14_c);
static real_T *c14_access_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b);
static void init_dsm_address_info(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_Control_Loop4_2Model = 0U;
}

static void initialize_params_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  real_T c14_hoistedGlobal;
  real_T c14_u;
  const mxArray *c14_b_y = NULL;
  int32_T c14_i0;
  real_T c14_b_u[4];
  const mxArray *c14_c_y = NULL;
  real_T c14_b_hoistedGlobal;
  real_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  uint8_T c14_c_hoistedGlobal;
  uint8_T c14_d_u;
  const mxArray *c14_e_y = NULL;
  real_T *c14_U_Est;
  real_T *c14_Y_Est;
  real_T (*c14_X_Est)[4];
  c14_U_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_Y_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_X_Est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(4), FALSE);
  c14_hoistedGlobal = *c14_U_Est;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  for (c14_i0 = 0; c14_i0 < 4; c14_i0++) {
    c14_b_u[c14_i0] = (*c14_X_Est)[c14_i0];
  }

  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", c14_b_u, 0, 0U, 1U, 0U, 1, 4),
                FALSE);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_b_hoistedGlobal = *c14_Y_Est;
  c14_c_u = c14_b_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  c14_c_hoistedGlobal = chartInstance->c14_is_active_c14_Control_Loop4_2Model;
  c14_d_u = c14_c_hoistedGlobal;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c14_y, 3, c14_e_y);
  sf_mex_assign(&c14_st, c14_y, FALSE);
  return c14_st;
}

static void set_sim_state_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv0[4];
  int32_T c14_i1;
  real_T *c14_U_Est;
  real_T *c14_Y_Est;
  real_T (*c14_X_Est)[4];
  c14_U_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_Y_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_X_Est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  *c14_U_Est = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 0)), "U_Est");
  c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
    "X_Est", c14_dv0);
  for (c14_i1 = 0; c14_i1 < 4; c14_i1++) {
    (*c14_X_Est)[c14_i1] = c14_dv0[c14_i1];
  }

  *c14_Y_Est = c14_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 2)), "Y_Est");
  chartInstance->c14_is_active_c14_Control_Loop4_2Model = c14_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 3)),
     "is_active_c14_Control_Loop4_2Model");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c14_Control_Loop4_2Model(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  int32_T c14_i2;
  real_T *c14_U;
  real_T *c14_Y;
  real_T *c14_Y_Est;
  real_T *c14_U_Est;
  real_T (*c14_X_Est)[4];
  c14_U_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_Y_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_Y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_X_Est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  for (c14_i2 = 0; c14_i2 < 4; c14_i2++) {
    _SFD_DATA_RANGE_CHECK((*c14_X_Est)[c14_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c14_U, 1U);
  _SFD_DATA_RANGE_CHECK(*c14_Y, 2U);
  _SFD_DATA_RANGE_CHECK(*c14_Y_Est, 4U);
  _SFD_DATA_RANGE_CHECK(*c14_U_Est, 6U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_Control_Loop4_2Model(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c14_chartstep_c14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  real_T c14_hoistedGlobal;
  real_T c14_b_hoistedGlobal;
  real_T c14_U;
  real_T c14_Y;
  uint32_T c14_debug_family_var_map[17];
  real_T c14_F[16];
  real_T c14_B[4];
  real_T c14_K[4];
  real_T c14_H[4];
  real_T c14_N_r;
  real_T c14_Q[16];
  real_T c14_K_k[4];
  real_T c14_y_k;
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 3.0;
  real_T c14_X_Est[4];
  real_T c14_Y_Est;
  real_T c14_U_Est;
  int32_T c14_i3;
  static real_T c14_a[16] = { 1.0, 0.0, 0.0, 0.0, 0.4148, 0.2064, 0.4088, 0.517,
    0.08176, 0.1034, 0.8958, -0.1579, 0.1563, 0.2369, 0.8036, 0.6589 };

  int32_T c14_i4;
  static real_T c14_b_a[4] = { 0.05852, 0.07937, -0.04088, -0.05169 };

  int32_T c14_i5;
  static real_T c14_c_a[4] = { -1.0076, -0.6317, -0.1954, -0.3814 };

  int32_T c14_i6;
  static real_T c14_d_a[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c14_i7;
  static real_T c14_dv1[16] = { 0.8, 0.0, 0.0, 0.0, 0.0, 0.8, 0.0, 0.0, 0.0, 0.0,
    0.8, 0.0, 0.0, 0.0, 0.0, 0.8 };

  int32_T c14_i8;
  int32_T c14_i9;
  int32_T c14_i10;
  real_T c14_c_hoistedGlobal[4];
  int32_T c14_i11;
  real_T c14_y[4];
  int32_T c14_i12;
  int32_T c14_i13;
  static real_T c14_e_a[16] = { 1.058964752, 0.079973212, -0.041190688,
    -0.052082844, 0.451767084, 0.256538029, 0.382976104, 0.484347427,
    0.093194808, 0.118908898, 0.887812048, -0.168000226, 0.178619528,
    0.267171718, 0.788008368, 0.639185434 };

  real_T c14_b;
  int32_T c14_i14;
  real_T c14_b_y[4];
  int32_T c14_i15;
  int32_T c14_i16;
  real_T c14_d_hoistedGlobal[16];
  int32_T c14_i17;
  int32_T c14_i18;
  int32_T c14_i19;
  real_T c14_c_y[16];
  int32_T c14_i20;
  int32_T c14_i21;
  int32_T c14_i22;
  int32_T c14_i23;
  int32_T c14_i24;
  int32_T c14_i25;
  int32_T c14_i26;
  static real_T c14_b_b[16] = { 1.0, 0.4148, 0.08176, 0.1563, 0.0, 0.2064,
    0.1034, 0.2369, 0.0, 0.4088, 0.8958, 0.8036, 0.0, 0.517, -0.1579, 0.6589 };

  int32_T c14_i27;
  int32_T c14_i28;
  real_T c14_d_y;
  int32_T c14_k;
  int32_T c14_b_k;
  static real_T c14_c_b[4] = { 1.0, 0.0, 0.0, 0.0 };

  int32_T c14_i29;
  int32_T c14_i30;
  int32_T c14_i31;
  int32_T c14_i32;
  int32_T c14_i33;
  int32_T c14_i34;
  int32_T c14_i35;
  real_T c14_e_y[4];
  int32_T c14_i36;
  real_T c14_f_y;
  int32_T c14_c_k;
  int32_T c14_d_k;
  real_T c14_b_B;
  real_T c14_g_y;
  real_T c14_h_y;
  int32_T c14_i37;
  int32_T c14_i38;
  int32_T c14_i39;
  real_T c14_d_b;
  int32_T c14_i40;
  int32_T c14_i41;
  int32_T c14_i42;
  int32_T c14_i43;
  int32_T c14_i44;
  int32_T c14_i45;
  int32_T c14_i46;
  real_T c14_f_a[16];
  int32_T c14_i47;
  int32_T c14_i48;
  int32_T c14_i49;
  int32_T c14_i50;
  int32_T c14_i51;
  int32_T c14_i52;
  int32_T c14_i53;
  int32_T c14_i54;
  int32_T c14_i55;
  int32_T c14_e_k;
  int32_T c14_f_k;
  int32_T c14_i56;
  int32_T c14_g_k;
  int32_T c14_h_k;
  static real_T c14_dv2[4] = { -1.0076, -0.6317, -0.1954, -0.3814 };

  int32_T c14_i57;
  real_T *c14_b_U;
  real_T *c14_b_Y;
  real_T *c14_b_Y_Est;
  real_T *c14_b_U_Est;
  real_T (*c14_b_X_Est)[4];
  c14_b_U_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c14_b_Y_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c14_b_Y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_b_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_b_X_Est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
  c14_hoistedGlobal = *c14_b_U;
  c14_b_hoistedGlobal = *c14_b_Y;
  c14_U = c14_hoistedGlobal;
  c14_Y = c14_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c14_debug_family_names,
    c14_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_F, 0U, c14_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_B, 1U, c14_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_K, 2U, c14_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c14_H, 3U, c14_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_N_r, 4U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_Q, 5U, c14_sf_marshallOut,
    c14_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_K_k, 6U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_y_k, 7U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 8U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 9U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_U, 10U, c14_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c14_Y, 11U, c14_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c14_X_Est, 12U, c14_b_sf_marshallOut,
    c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_Y_Est, 13U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_U_Est, 14U, c14_c_sf_marshallOut,
    c14_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c14_X_k_4_address, 15U,
    c14_b_sf_marshallOut, c14_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(*chartInstance->c14_P_k_4_address, 16U,
    c14_sf_marshallOut, c14_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 3);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 6);
  for (c14_i3 = 0; c14_i3 < 16; c14_i3++) {
    c14_F[c14_i3] = c14_a[c14_i3];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 7);
  for (c14_i4 = 0; c14_i4 < 4; c14_i4++) {
    c14_B[c14_i4] = c14_b_a[c14_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 13);
  for (c14_i5 = 0; c14_i5 < 4; c14_i5++) {
    c14_K[c14_i5] = c14_c_a[c14_i5];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 14);
  for (c14_i6 = 0; c14_i6 < 4; c14_i6++) {
    c14_H[c14_i6] = c14_d_a[c14_i6];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 15);
  c14_N_r = 10.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 16);
  for (c14_i7 = 0; c14_i7 < 16; c14_i7++) {
    c14_Q[c14_i7] = c14_dv1[c14_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 17);
  for (c14_i8 = 0; c14_i8 < 4; c14_i8++) {
    c14_K_k[c14_i8] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 18);
  for (c14_i9 = 0; c14_i9 < 4; c14_i9++) {
    c14_X_Est[c14_i9] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 19);
  c14_Y_Est = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 24);
  for (c14_i10 = 0; c14_i10 < 4; c14_i10++) {
    c14_c_hoistedGlobal[c14_i10] = c14_get_X_k_4(chartInstance, c14_i10);
  }

  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
  for (c14_i11 = 0; c14_i11 < 4; c14_i11++) {
    c14_y[c14_i11] = 0.0;
    c14_i12 = 0;
    for (c14_i13 = 0; c14_i13 < 4; c14_i13++) {
      c14_y[c14_i11] += c14_e_a[c14_i12 + c14_i11] * c14_c_hoistedGlobal[c14_i13];
      c14_i12 += 4;
    }
  }

  c14_b = c14_U;
  for (c14_i14 = 0; c14_i14 < 4; c14_i14++) {
    c14_b_y[c14_i14] = c14_b_a[c14_i14] * c14_b;
  }

  for (c14_i15 = 0; c14_i15 < 4; c14_i15++) {
    c14_set_X_k_4(chartInstance, c14_i15, c14_y[c14_i15] + c14_b_y[c14_i15]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 28);
  for (c14_i16 = 0; c14_i16 < 16; c14_i16++) {
    c14_d_hoistedGlobal[c14_i16] = c14_get_P_k_4(chartInstance, c14_i16);
  }

  c14_b_eml_scalar_eg(chartInstance);
  c14_b_eml_scalar_eg(chartInstance);
  for (c14_i17 = 0; c14_i17 < 4; c14_i17++) {
    c14_i18 = 0;
    for (c14_i19 = 0; c14_i19 < 4; c14_i19++) {
      c14_c_y[c14_i18 + c14_i17] = 0.0;
      c14_i20 = 0;
      for (c14_i21 = 0; c14_i21 < 4; c14_i21++) {
        c14_c_y[c14_i18 + c14_i17] += c14_a[c14_i20 + c14_i17] *
          c14_d_hoistedGlobal[c14_i21 + c14_i18];
        c14_i20 += 4;
      }

      c14_i18 += 4;
    }
  }

  c14_b_eml_scalar_eg(chartInstance);
  c14_b_eml_scalar_eg(chartInstance);
  for (c14_i22 = 0; c14_i22 < 4; c14_i22++) {
    c14_i23 = 0;
    for (c14_i24 = 0; c14_i24 < 4; c14_i24++) {
      c14_d_hoistedGlobal[c14_i23 + c14_i22] = 0.0;
      c14_i25 = 0;
      for (c14_i26 = 0; c14_i26 < 4; c14_i26++) {
        c14_d_hoistedGlobal[c14_i23 + c14_i22] += c14_c_y[c14_i25 + c14_i22] *
          c14_b_b[c14_i26 + c14_i23];
        c14_i25 += 4;
      }

      c14_i23 += 4;
    }
  }

  for (c14_i27 = 0; c14_i27 < 16; c14_i27++) {
    c14_set_P_k_4(chartInstance, c14_i27, c14_d_hoistedGlobal[c14_i27] +
                  c14_Q[c14_i27]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 31);
  for (c14_i28 = 0; c14_i28 < 4; c14_i28++) {
    c14_c_hoistedGlobal[c14_i28] = c14_get_X_k_4(chartInstance, c14_i28);
  }

  c14_c_eml_scalar_eg(chartInstance);
  c14_c_eml_scalar_eg(chartInstance);
  c14_d_y = 0.0;
  for (c14_k = 1; c14_k < 5; c14_k++) {
    c14_b_k = c14_k;
    c14_d_y += c14_c_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_b_k), 1, 4, 1, 0) - 1] *
      c14_c_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_b_k), 1, 4, 1, 0) - 1];
  }

  c14_y_k = c14_Y - c14_d_y;
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 34);
  for (c14_i29 = 0; c14_i29 < 16; c14_i29++) {
    c14_d_hoistedGlobal[c14_i29] = c14_get_P_k_4(chartInstance, c14_i29);
  }

  c14_eml_scalar_eg(chartInstance);
  c14_eml_scalar_eg(chartInstance);
  for (c14_i30 = 0; c14_i30 < 4; c14_i30++) {
    c14_y[c14_i30] = 0.0;
    c14_i31 = 0;
    for (c14_i32 = 0; c14_i32 < 4; c14_i32++) {
      c14_y[c14_i30] += c14_d_hoistedGlobal[c14_i31 + c14_i30] * c14_c_b[c14_i32];
      c14_i31 += 4;
    }
  }

  for (c14_i33 = 0; c14_i33 < 16; c14_i33++) {
    c14_d_hoistedGlobal[c14_i33] = c14_get_P_k_4(chartInstance, c14_i33);
  }

  c14_d_eml_scalar_eg(chartInstance);
  c14_d_eml_scalar_eg(chartInstance);
  c14_i34 = 0;
  for (c14_i35 = 0; c14_i35 < 4; c14_i35++) {
    c14_e_y[c14_i35] = 0.0;
    for (c14_i36 = 0; c14_i36 < 4; c14_i36++) {
      c14_e_y[c14_i35] += c14_d_a[c14_i36] * c14_d_hoistedGlobal[c14_i36 +
        c14_i34];
    }

    c14_i34 += 4;
  }

  c14_c_eml_scalar_eg(chartInstance);
  c14_c_eml_scalar_eg(chartInstance);
  c14_f_y = 0.0;
  for (c14_c_k = 1; c14_c_k < 5; c14_c_k++) {
    c14_d_k = c14_c_k;
    c14_f_y += c14_e_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_d_k), 1, 4, 1, 0) - 1] *
      c14_c_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c14_d_k), 1, 4, 1, 0) - 1];
  }

  c14_b_B = c14_N_r + c14_f_y;
  c14_g_y = c14_b_B;
  c14_h_y = c14_g_y;
  for (c14_i37 = 0; c14_i37 < 4; c14_i37++) {
    c14_K_k[c14_i37] = c14_y[c14_i37] / c14_h_y;
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 37);
  for (c14_i38 = 0; c14_i38 < 4; c14_i38++) {
    c14_c_hoistedGlobal[c14_i38] = c14_get_X_k_4(chartInstance, c14_i38);
  }

  for (c14_i39 = 0; c14_i39 < 4; c14_i39++) {
    c14_b_y[c14_i39] = c14_K_k[c14_i39];
  }

  c14_d_b = c14_y_k;
  for (c14_i40 = 0; c14_i40 < 4; c14_i40++) {
    c14_b_y[c14_i40] *= c14_d_b;
  }

  for (c14_i41 = 0; c14_i41 < 4; c14_i41++) {
    c14_set_X_k_4(chartInstance, c14_i41, c14_c_hoistedGlobal[c14_i41] +
                  c14_b_y[c14_i41]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 1);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 39);
  for (c14_i42 = 0; c14_i42 < 4; c14_i42++) {
    c14_b_y[c14_i42] = c14_K_k[c14_i42];
  }

  for (c14_i43 = 0; c14_i43 < 4; c14_i43++) {
    c14_i44 = 0;
    for (c14_i45 = 0; c14_i45 < 4; c14_i45++) {
      c14_c_y[c14_i44 + c14_i43] = c14_b_y[c14_i43] * c14_d_a[c14_i45];
      c14_i44 += 4;
    }
  }

  for (c14_i46 = 0; c14_i46 < 16; c14_i46++) {
    c14_d_hoistedGlobal[c14_i46] = c14_get_P_k_4(chartInstance, c14_i46);
  }

  c14_eye(chartInstance, c14_f_a);
  for (c14_i47 = 0; c14_i47 < 16; c14_i47++) {
    c14_f_a[c14_i47] -= c14_c_y[c14_i47];
  }

  c14_b_eml_scalar_eg(chartInstance);
  c14_b_eml_scalar_eg(chartInstance);
  for (c14_i48 = 0; c14_i48 < 4; c14_i48++) {
    c14_i49 = 0;
    for (c14_i50 = 0; c14_i50 < 4; c14_i50++) {
      c14_c_y[c14_i49 + c14_i48] = 0.0;
      c14_i51 = 0;
      for (c14_i52 = 0; c14_i52 < 4; c14_i52++) {
        c14_c_y[c14_i49 + c14_i48] += c14_f_a[c14_i51 + c14_i48] *
          c14_d_hoistedGlobal[c14_i52 + c14_i49];
        c14_i51 += 4;
      }

      c14_i49 += 4;
    }
  }

  for (c14_i53 = 0; c14_i53 < 16; c14_i53++) {
    c14_set_P_k_4(chartInstance, c14_i53, c14_c_y[c14_i53]);
  }

  ssUpdateDataStoreLog(chartInstance->S, 0);
  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 50);
  for (c14_i54 = 0; c14_i54 < 4; c14_i54++) {
    c14_X_Est[c14_i54] = -c14_get_X_k_4(chartInstance, c14_i54);
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 52);
  for (c14_i55 = 0; c14_i55 < 4; c14_i55++) {
    c14_b_y[c14_i55] = c14_X_Est[c14_i55];
  }

  c14_c_eml_scalar_eg(chartInstance);
  c14_c_eml_scalar_eg(chartInstance);
  c14_Y_Est = 0.0;
  for (c14_e_k = 1; c14_e_k < 5; c14_e_k++) {
    c14_f_k = c14_e_k;
    c14_Y_Est += c14_c_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_f_k), 1, 4, 1, 0) - 1] *
      c14_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c14_f_k), 1, 4, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, 53);
  for (c14_i56 = 0; c14_i56 < 4; c14_i56++) {
    c14_b_y[c14_i56] = c14_X_Est[c14_i56];
  }

  c14_c_eml_scalar_eg(chartInstance);
  c14_c_eml_scalar_eg(chartInstance);
  c14_U_Est = 0.0;
  for (c14_g_k = 1; c14_g_k < 5; c14_g_k++) {
    c14_h_k = c14_g_k;
    c14_U_Est += c14_dv2[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_h_k), 1, 4, 1, 0) - 1] *
      c14_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c14_h_k), 1, 4, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c14_sfEvent, -53);
  _SFD_SYMBOL_SCOPE_POP();
  for (c14_i57 = 0; c14_i57 < 4; c14_i57++) {
    (*c14_b_X_Est)[c14_i57] = c14_X_Est[c14_i57];
  }

  *c14_b_Y_Est = c14_Y_Est;
  *c14_b_U_Est = c14_U_Est;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_Control_Loop4_2Model
  (SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i58;
  int32_T c14_i59;
  int32_T c14_i60;
  real_T c14_b_inData[16];
  int32_T c14_i61;
  int32_T c14_i62;
  int32_T c14_i63;
  real_T c14_u[16];
  const mxArray *c14_y = NULL;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_i58 = 0;
  for (c14_i59 = 0; c14_i59 < 4; c14_i59++) {
    for (c14_i60 = 0; c14_i60 < 4; c14_i60++) {
      c14_b_inData[c14_i60 + c14_i58] = (*(real_T (*)[16])c14_inData)[c14_i60 +
        c14_i58];
    }

    c14_i58 += 4;
  }

  c14_i61 = 0;
  for (c14_i62 = 0; c14_i62 < 4; c14_i62++) {
    for (c14_i63 = 0; c14_i63 < 4; c14_i63++) {
      c14_u[c14_i63 + c14_i61] = c14_b_inData[c14_i63 + c14_i61];
    }

    c14_i61 += 4;
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[16])
{
  real_T c14_dv3[16];
  int32_T c14_i64;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv3, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c14_i64 = 0; c14_i64 < 16; c14_i64++) {
    c14_y[c14_i64] = c14_dv3[c14_i64];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_P_k_4;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[16];
  int32_T c14_i65;
  int32_T c14_i66;
  int32_T c14_i67;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_P_k_4 = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_P_k_4), &c14_thisId, c14_y);
  sf_mex_destroy(&c14_P_k_4);
  c14_i65 = 0;
  for (c14_i66 = 0; c14_i66 < 4; c14_i66++) {
    for (c14_i67 = 0; c14_i67 < 4; c14_i67++) {
      (*(real_T (*)[16])c14_outData)[c14_i67 + c14_i65] = c14_y[c14_i67 +
        c14_i65];
    }

    c14_i65 += 4;
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i68;
  real_T c14_b_inData[4];
  int32_T c14_i69;
  real_T c14_u[4];
  const mxArray *c14_y = NULL;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i68 = 0; c14_i68 < 4; c14_i68++) {
    c14_b_inData[c14_i68] = (*(real_T (*)[4])c14_inData)[c14_i68];
  }

  for (c14_i69 = 0; c14_i69 < 4; c14_i69++) {
    c14_u[c14_i69] = c14_b_inData[c14_i69];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static void c14_b_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_X_k_4, const char_T *c14_identifier, real_T
  c14_y[4])
{
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_X_k_4), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_X_k_4);
}

static void c14_c_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId,
  real_T c14_y[4])
{
  real_T c14_dv4[4];
  int32_T c14_i70;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), c14_dv4, 1, 0, 0U, 1, 0U, 1, 4);
  for (c14_i70 = 0; c14_i70 < 4; c14_i70++) {
    c14_y[c14_i70] = c14_dv4[c14_i70];
  }

  sf_mex_destroy(&c14_u);
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_X_k_4;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y[4];
  int32_T c14_i71;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_X_k_4 = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_X_k_4), &c14_thisId,
    c14_y);
  sf_mex_destroy(&c14_X_k_4);
  for (c14_i71 = 0; c14_i71 < 4; c14_i71++) {
    (*(real_T (*)[4])c14_outData)[c14_i71] = c14_y[c14_i71];
  }

  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static real_T c14_d_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_U_Est, const char_T *c14_identifier)
{
  real_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_U_Est),
    &c14_thisId);
  sf_mex_destroy(&c14_U_Est);
  return c14_y;
}

static real_T c14_e_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_U_Est;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_U_Est = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_U_Est),
    &c14_thisId);
  sf_mex_destroy(&c14_U_Est);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_i72;
  real_T c14_b_inData[4];
  int32_T c14_i73;
  real_T c14_u[4];
  const mxArray *c14_y = NULL;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  for (c14_i72 = 0; c14_i72 < 4; c14_i72++) {
    c14_b_inData[c14_i72] = (*(real_T (*)[4])c14_inData)[c14_i72];
  }

  for (c14_i73 = 0; c14_i73 < 4; c14_i73++) {
    c14_u[c14_i73] = c14_b_inData[c14_i73];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

const mxArray *sf_c14_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 47, 1),
                FALSE);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  const mxArray *c14_rhs3 = NULL;
  const mxArray *c14_lhs3 = NULL;
  const mxArray *c14_rhs4 = NULL;
  const mxArray *c14_lhs4 = NULL;
  const mxArray *c14_rhs5 = NULL;
  const mxArray *c14_lhs5 = NULL;
  const mxArray *c14_rhs6 = NULL;
  const mxArray *c14_lhs6 = NULL;
  const mxArray *c14_rhs7 = NULL;
  const mxArray *c14_lhs7 = NULL;
  const mxArray *c14_rhs8 = NULL;
  const mxArray *c14_lhs8 = NULL;
  const mxArray *c14_rhs9 = NULL;
  const mxArray *c14_lhs9 = NULL;
  const mxArray *c14_rhs10 = NULL;
  const mxArray *c14_lhs10 = NULL;
  const mxArray *c14_rhs11 = NULL;
  const mxArray *c14_lhs11 = NULL;
  const mxArray *c14_rhs12 = NULL;
  const mxArray *c14_lhs12 = NULL;
  const mxArray *c14_rhs13 = NULL;
  const mxArray *c14_lhs13 = NULL;
  const mxArray *c14_rhs14 = NULL;
  const mxArray *c14_lhs14 = NULL;
  const mxArray *c14_rhs15 = NULL;
  const mxArray *c14_lhs15 = NULL;
  const mxArray *c14_rhs16 = NULL;
  const mxArray *c14_lhs16 = NULL;
  const mxArray *c14_rhs17 = NULL;
  const mxArray *c14_lhs17 = NULL;
  const mxArray *c14_rhs18 = NULL;
  const mxArray *c14_lhs18 = NULL;
  const mxArray *c14_rhs19 = NULL;
  const mxArray *c14_lhs19 = NULL;
  const mxArray *c14_rhs20 = NULL;
  const mxArray *c14_lhs20 = NULL;
  const mxArray *c14_rhs21 = NULL;
  const mxArray *c14_lhs21 = NULL;
  const mxArray *c14_rhs22 = NULL;
  const mxArray *c14_lhs22 = NULL;
  const mxArray *c14_rhs23 = NULL;
  const mxArray *c14_lhs23 = NULL;
  const mxArray *c14_rhs24 = NULL;
  const mxArray *c14_lhs24 = NULL;
  const mxArray *c14_rhs25 = NULL;
  const mxArray *c14_lhs25 = NULL;
  const mxArray *c14_rhs26 = NULL;
  const mxArray *c14_lhs26 = NULL;
  const mxArray *c14_rhs27 = NULL;
  const mxArray *c14_lhs27 = NULL;
  const mxArray *c14_rhs28 = NULL;
  const mxArray *c14_lhs28 = NULL;
  const mxArray *c14_rhs29 = NULL;
  const mxArray *c14_lhs29 = NULL;
  const mxArray *c14_rhs30 = NULL;
  const mxArray *c14_lhs30 = NULL;
  const mxArray *c14_rhs31 = NULL;
  const mxArray *c14_lhs31 = NULL;
  const mxArray *c14_rhs32 = NULL;
  const mxArray *c14_lhs32 = NULL;
  const mxArray *c14_rhs33 = NULL;
  const mxArray *c14_lhs33 = NULL;
  const mxArray *c14_rhs34 = NULL;
  const mxArray *c14_lhs34 = NULL;
  const mxArray *c14_rhs35 = NULL;
  const mxArray *c14_lhs35 = NULL;
  const mxArray *c14_rhs36 = NULL;
  const mxArray *c14_lhs36 = NULL;
  const mxArray *c14_rhs37 = NULL;
  const mxArray *c14_lhs37 = NULL;
  const mxArray *c14_rhs38 = NULL;
  const mxArray *c14_lhs38 = NULL;
  const mxArray *c14_rhs39 = NULL;
  const mxArray *c14_lhs39 = NULL;
  const mxArray *c14_rhs40 = NULL;
  const mxArray *c14_lhs40 = NULL;
  const mxArray *c14_rhs41 = NULL;
  const mxArray *c14_lhs41 = NULL;
  const mxArray *c14_rhs42 = NULL;
  const mxArray *c14_lhs42 = NULL;
  const mxArray *c14_rhs43 = NULL;
  const mxArray *c14_lhs43 = NULL;
  const mxArray *c14_rhs44 = NULL;
  const mxArray *c14_lhs44 = NULL;
  const mxArray *c14_rhs45 = NULL;
  const mxArray *c14_lhs45 = NULL;
  const mxArray *c14_rhs46 = NULL;
  const mxArray *c14_lhs46 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eye"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1368161430U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1368161430U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("isinf"), "name", "name", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688656U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c14_rhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs3, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c14_rhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs4, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797182U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c14_rhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs5, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmax"), "name", "name", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c14_rhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs6, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmin"), "name", "name", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c14_rhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs7, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1326703122U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c14_rhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs8, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c14_rhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs9, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmin"), "name", "name", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c14_rhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs10, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size"),
                  "context", "context", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mtimes"), "name", "name", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c14_rhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs11, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m!common_checks"),
                  "context", "context", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c14_rhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs12, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c14_rhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs13, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmax"), "name", "name", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c14_rhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs14, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346488740U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c14_rhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs15, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("intmax"), "name", "name", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1362236682U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c14_rhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs16, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mtimes"), "name", "name", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c14_rhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs17, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c14_rhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs18, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c14_rhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs19, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688670U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c14_rhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs20, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1299051568U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c14_rhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs21, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold"),
                  "context", "context", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mtimes"), "name", "name", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688678U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c14_rhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs22, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c14_rhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs23, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c14_rhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs24, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_refblas_xgemm"), "name",
                  "name", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1360257150U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c14_rhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs25, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688670U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c14_rhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs26, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1299051568U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c14_rhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs27, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_xdot"), "name", "name",
                  28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688668U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c14_rhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs28, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_blas_inline"), "name",
                  "name", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1299051568U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c14_rhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs29, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c14_rhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs30, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_refblas_xdot"), "name",
                  "name", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1299051572U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c14_rhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs31, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_refblas_xdotx"), "name",
                  "name", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1360257150U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c14_rhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs32, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c14_rhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs33, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c14_rhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs34, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797178U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c14_rhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs35, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c14_rhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs36, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797180U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c14_rhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs37, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c14_rhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs38, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 39);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797178U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c14_rhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs39, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 40);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1323145378U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c14_rhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs40, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"),
                  "context", "context", 41);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 41);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1346488740U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c14_rhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs41, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 42);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("mrdivide"), "name", "name",
                  42);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1373284908U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1319708366U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c14_rhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs42, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 43);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("rdivide"), "name", "name",
                  43);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c14_rhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs43, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 44);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c14_rhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs44, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 45);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c14_rhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs45, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 46);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_div"), "name", "name",
                  46);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688666U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c14_rhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_assign(&c14_lhs46, sf_mex_createcellarray(0), FALSE);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs46), "lhs", "lhs",
                  46);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
  sf_mex_destroy(&c14_rhs3);
  sf_mex_destroy(&c14_lhs3);
  sf_mex_destroy(&c14_rhs4);
  sf_mex_destroy(&c14_lhs4);
  sf_mex_destroy(&c14_rhs5);
  sf_mex_destroy(&c14_lhs5);
  sf_mex_destroy(&c14_rhs6);
  sf_mex_destroy(&c14_lhs6);
  sf_mex_destroy(&c14_rhs7);
  sf_mex_destroy(&c14_lhs7);
  sf_mex_destroy(&c14_rhs8);
  sf_mex_destroy(&c14_lhs8);
  sf_mex_destroy(&c14_rhs9);
  sf_mex_destroy(&c14_lhs9);
  sf_mex_destroy(&c14_rhs10);
  sf_mex_destroy(&c14_lhs10);
  sf_mex_destroy(&c14_rhs11);
  sf_mex_destroy(&c14_lhs11);
  sf_mex_destroy(&c14_rhs12);
  sf_mex_destroy(&c14_lhs12);
  sf_mex_destroy(&c14_rhs13);
  sf_mex_destroy(&c14_lhs13);
  sf_mex_destroy(&c14_rhs14);
  sf_mex_destroy(&c14_lhs14);
  sf_mex_destroy(&c14_rhs15);
  sf_mex_destroy(&c14_lhs15);
  sf_mex_destroy(&c14_rhs16);
  sf_mex_destroy(&c14_lhs16);
  sf_mex_destroy(&c14_rhs17);
  sf_mex_destroy(&c14_lhs17);
  sf_mex_destroy(&c14_rhs18);
  sf_mex_destroy(&c14_lhs18);
  sf_mex_destroy(&c14_rhs19);
  sf_mex_destroy(&c14_lhs19);
  sf_mex_destroy(&c14_rhs20);
  sf_mex_destroy(&c14_lhs20);
  sf_mex_destroy(&c14_rhs21);
  sf_mex_destroy(&c14_lhs21);
  sf_mex_destroy(&c14_rhs22);
  sf_mex_destroy(&c14_lhs22);
  sf_mex_destroy(&c14_rhs23);
  sf_mex_destroy(&c14_lhs23);
  sf_mex_destroy(&c14_rhs24);
  sf_mex_destroy(&c14_lhs24);
  sf_mex_destroy(&c14_rhs25);
  sf_mex_destroy(&c14_lhs25);
  sf_mex_destroy(&c14_rhs26);
  sf_mex_destroy(&c14_lhs26);
  sf_mex_destroy(&c14_rhs27);
  sf_mex_destroy(&c14_lhs27);
  sf_mex_destroy(&c14_rhs28);
  sf_mex_destroy(&c14_lhs28);
  sf_mex_destroy(&c14_rhs29);
  sf_mex_destroy(&c14_lhs29);
  sf_mex_destroy(&c14_rhs30);
  sf_mex_destroy(&c14_lhs30);
  sf_mex_destroy(&c14_rhs31);
  sf_mex_destroy(&c14_lhs31);
  sf_mex_destroy(&c14_rhs32);
  sf_mex_destroy(&c14_lhs32);
  sf_mex_destroy(&c14_rhs33);
  sf_mex_destroy(&c14_lhs33);
  sf_mex_destroy(&c14_rhs34);
  sf_mex_destroy(&c14_lhs34);
  sf_mex_destroy(&c14_rhs35);
  sf_mex_destroy(&c14_lhs35);
  sf_mex_destroy(&c14_rhs36);
  sf_mex_destroy(&c14_lhs36);
  sf_mex_destroy(&c14_rhs37);
  sf_mex_destroy(&c14_lhs37);
  sf_mex_destroy(&c14_rhs38);
  sf_mex_destroy(&c14_lhs38);
  sf_mex_destroy(&c14_rhs39);
  sf_mex_destroy(&c14_lhs39);
  sf_mex_destroy(&c14_rhs40);
  sf_mex_destroy(&c14_lhs40);
  sf_mex_destroy(&c14_rhs41);
  sf_mex_destroy(&c14_lhs41);
  sf_mex_destroy(&c14_rhs42);
  sf_mex_destroy(&c14_lhs42);
  sf_mex_destroy(&c14_rhs43);
  sf_mex_destroy(&c14_lhs43);
  sf_mex_destroy(&c14_rhs44);
  sf_mex_destroy(&c14_lhs44);
  sf_mex_destroy(&c14_rhs45);
  sf_mex_destroy(&c14_lhs45);
  sf_mex_destroy(&c14_rhs46);
  sf_mex_destroy(&c14_lhs46);
}

static const mxArray *c14_emlrt_marshallOut(char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), FALSE);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), FALSE);
  return c14_y;
}

static void c14_eye(SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance,
                    real_T c14_I[16])
{
  int32_T c14_i74;
  int32_T c14_k;
  int32_T c14_b_k;
  for (c14_i74 = 0; c14_i74 < 16; c14_i74++) {
    c14_I[c14_i74] = 0.0;
  }

  for (c14_k = 1; c14_k < 5; c14_k++) {
    c14_b_k = c14_k;
    c14_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c14_b_k), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c14_b_k), 1, 4, 2, 0) - 1)
            << 2)) - 1] = 1.0;
  }
}

static void c14_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static void c14_b_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static void c14_c_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static void c14_d_eml_scalar_eg(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, FALSE);
  return c14_mxArrayOutData;
}

static int32_T c14_f_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i75;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i75, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i75;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint8_T c14_g_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_Control_Loop4_2Model, const
  char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_is_active_c14_Control_Loop4_2Model), &c14_thisId);
  sf_mex_destroy(&c14_b_is_active_c14_Control_Loop4_2Model);
  return c14_y;
}

static uint8_T c14_h_emlrt_marshallIn(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static real_T c14_get_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c14_b);
  if (chartInstance->c14_P_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P_k_4\' (#146) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c14_P_k_4_address)[c14_b];
}

static void c14_set_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b, real_T c14_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c14_b);
  if (chartInstance->c14_P_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P_k_4\' (#146) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c14_P_k_4_address)[c14_b] = c14_c;
}

static real_T *c14_access_P_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  real_T *c14_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c14_P_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'P_k_4\' (#146) in the initialization routine of the chart.\n");
  }

  c14_c = *chartInstance->c14_P_k_4_address;
  if (c14_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c14_c;
}

static real_T c14_get_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 1, NULL, c14_b);
  if (chartInstance->c14_X_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'X_k_4\' (#148) in the initialization routine of the chart.\n");
  }

  return (*chartInstance->c14_X_k_4_address)[c14_b];
}

static void c14_set_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b, real_T c14_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 1, NULL, c14_b);
  if (chartInstance->c14_X_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'X_k_4\' (#148) in the initialization routine of the chart.\n");
  }

  (*chartInstance->c14_X_k_4_address)[c14_b] = c14_c;
}

static real_T *c14_access_X_k_4(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance, uint32_T c14_b)
{
  real_T *c14_c;
  ssReadFromDataStore(chartInstance->S, 1, NULL);
  if (chartInstance->c14_X_k_4_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'X_k_4\' (#148) in the initialization routine of the chart.\n");
  }

  c14_c = *chartInstance->c14_X_k_4_address;
  if (c14_b == 0) {
    ssWriteToDataStore(chartInstance->S, 1, NULL);
  }

  return c14_c;
}

static void init_dsm_address_info(SFc14_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "P_k_4", (void **)
    &chartInstance->c14_P_k_4_address, &chartInstance->c14_P_k_4_index);
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "X_k_4", (void **)
    &chartInstance->c14_X_k_4_address, &chartInstance->c14_X_k_4_index);
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

void sf_c14_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3023556160U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3009063546U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1211459585U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2994972184U);
}

mxArray *sf_c14_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6H5l9MvmxBzqXMHEpvgU1D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[0] = (double)(4);
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

mxArray *sf_c14_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[29],T\"U_Est\",},{M[1],M[5],T\"X_Est\",},{M[1],M[24],T\"Y_Est\",},{M[8],M[0],T\"is_active_c14_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           14,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"X_Est");
          _SFD_SET_DATA_PROPS(1,1,1,0,"U");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Y");
          _SFD_SET_DATA_PROPS(3,11,0,0,"P_k_4");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Y_Est");
          _SFD_SET_DATA_PROPS(5,11,0,0,"X_k_4");
          _SFD_SET_DATA_PROPS(6,2,0,1,"U_Est");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1251);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
            c14_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshallOut,(MexInFcnForType)
            c14_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)
          c14_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)
            c14_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_c_sf_marshallOut,(MexInFcnForType)
          c14_c_sf_marshallIn);

        {
          real_T *c14_U;
          real_T *c14_Y;
          real_T *c14_Y_Est;
          real_T *c14_U_Est;
          real_T (*c14_X_Est)[4];
          c14_U_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c14_Y_Est = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c14_Y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c14_U = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c14_X_Est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_X_Est);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_U);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_Y);
          _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c14_P_k_4_address);
          _SFD_SET_DATA_VALUE_PTR(4U, c14_Y_Est);
          _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c14_X_k_4_address);
          _SFD_SET_DATA_VALUE_PTR(6U, c14_U_Est);
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
  return "Rf0R8enG7u2VSqWc7EunYG";
}

static void sf_opaque_initialize_c14_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_Control_Loop4_2Model
    ((SFc14_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c14_Control_Loop4_2Model((SFc14_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c14_Control_Loop4_2Model((SFc14_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c14_Control_Loop4_2Model((SFc14_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c14_Control_Loop4_2Model((SFc14_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_Control_Loop4_2Model
    ((SFc14_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_Control_Loop4_2Model();/* state var info */
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

extern void sf_internal_set_sim_state_c14_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_Control_Loop4_2Model
    ((SFc14_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c14_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c14_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c14_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c14_Control_Loop4_2Model((SFc14_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc14_Control_Loop4_2Model
    ((SFc14_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_Control_Loop4_2Model
      ((SFc14_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,14,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1809108382U));
  ssSetChecksum1(S,(2794946689U));
  ssSetChecksum2(S,(2042794165U));
  ssSetChecksum3(S,(99808463U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c14_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_Control_Loop4_2Model(SimStruct *S)
{
  SFc14_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc14_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc14_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_Control_Loop4_2Model;
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

void c14_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
