/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Control_Loop4_2Model_sfun.h"
#include "c11_Control_Loop4_2Model.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void initialize_params_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void enable_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void disable_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void set_sim_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void sf_c11_Control_Loop4_2Model(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance);
static void initSimStructsc11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_y, const char_T *c11_identifier, real_T
  c11_b_y[4]);
static void c11_b_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_d_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_e_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Control_Loop4_2Model, const
  char_T *c11_identifier);
static uint8_T c11_f_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_Control_Loop4_2Model = 0U;
}

static void initialize_params_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void enable_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[4];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T (*c11_d_y)[4];
  c11_d_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2), FALSE);
  for (c11_i0 = 0; c11_i0 < 4; c11_i0++) {
    c11_u[c11_i0] = (*c11_d_y)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_Control_Loop4_2Model;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[4];
  int32_T c11_i1;
  real_T (*c11_y)[4];
  c11_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)), "y",
                       c11_dv0);
  for (c11_i1 = 0; c11_i1 < 4; c11_i1++) {
    (*c11_y)[c11_i1] = c11_dv0[c11_i1];
  }

  chartInstance->c11_is_active_c11_Control_Loop4_2Model = c11_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_Control_Loop4_2Model");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_Control_Loop4_2Model(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void sf_c11_Control_Loop4_2Model(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance)
{
  int32_T c11_i2;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  uint32_T c11_debug_family_var_map[4];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_y[4];
  int32_T c11_i3;
  real_T *c11_b_u;
  real_T (*c11_b_y)[4];
  c11_b_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_b_u, 0U);
  for (c11_i2 = 0; c11_i2 < 4; c11_i2++) {
    _SFD_DATA_RANGE_CHECK((*c11_b_y)[c11_i2], 1U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_u;
  c11_u = c11_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_u, 2U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_y, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_y[0] = c11_u;
  c11_y[1] = c11_u;
  c11_y[2] = c11_u;
  c11_y[3] = c11_u;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i3 = 0; c11_i3 < 4; c11_i3++) {
    (*c11_b_y)[c11_i3] = c11_y[c11_i3];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Control_Loop4_2ModelMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc11_Control_Loop4_2Model
  (SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i4;
  real_T c11_b_inData[4];
  int32_T c11_i5;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i4 = 0; c11_i4 < 4; c11_i4++) {
    c11_b_inData[c11_i4] = (*(real_T (*)[4])c11_inData)[c11_i4];
  }

  for (c11_i5 = 0; c11_i5 < 4; c11_i5++) {
    c11_u[c11_i5] = c11_b_inData[c11_i5];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_y, const char_T *c11_identifier, real_T
  c11_b_y[4])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
}

static void c11_b_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4])
{
  real_T c11_dv1[4];
  int32_T c11_i6;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c11_i6 = 0; c11_i6 < 4; c11_i6++) {
    c11_y[c11_i6] = c11_dv1[c11_i6];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_y;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_b_y[4];
  int32_T c11_i7;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_y = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y), &c11_thisId, c11_b_y);
  sf_mex_destroy(&c11_y);
  for (c11_i7 = 0; c11_i7 < 4; c11_i7++) {
    (*(real_T (*)[4])c11_outData)[c11_i7] = c11_b_y[c11_i7];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Control_Loop4_2Model_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_d_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i8;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i8, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i8;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Control_Loop4_2Model, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_Control_Loop4_2Model), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_Control_Loop4_2Model);
  return c11_y;
}

static uint8_T c11_f_emlrt_marshallIn(SFc11_Control_Loop4_2ModelInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_Control_Loop4_2ModelInstanceStruct
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

void sf_c11_Control_Loop4_2Model_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(684676668U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2148834875U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1329771093U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(144771345U);
}

mxArray *sf_c11_Control_Loop4_2Model_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OvmHhmdxasN44ZJ6vczcxF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Control_Loop4_2Model_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Control_Loop4_2Model_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c11_Control_Loop4_2Model(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c11_Control_Loop4_2Model\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Control_Loop4_2Model_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
    chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Control_Loop4_2ModelMachineNumber_,
           11,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,45);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T *c11_u;
          real_T (*c11_y)[4];
          c11_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_u);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_y);
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
  return "NL1PKiyZOMF75aeGCmNoGC";
}

static void sf_opaque_initialize_c11_Control_Loop4_2Model(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Control_Loop4_2Model
    ((SFc11_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
  initialize_c11_Control_Loop4_2Model((SFc11_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_Control_Loop4_2Model(void *chartInstanceVar)
{
  enable_c11_Control_Loop4_2Model((SFc11_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Control_Loop4_2Model(void *chartInstanceVar)
{
  disable_c11_Control_Loop4_2Model((SFc11_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Control_Loop4_2Model(void *chartInstanceVar)
{
  sf_c11_Control_Loop4_2Model((SFc11_Control_Loop4_2ModelInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_Control_Loop4_2Model
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_Control_Loop4_2Model
    ((SFc11_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Control_Loop4_2Model();/* state var info */
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

extern void sf_internal_set_sim_state_c11_Control_Loop4_2Model(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Control_Loop4_2Model();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Control_Loop4_2Model
    ((SFc11_Control_Loop4_2ModelInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_Control_Loop4_2Model(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c11_Control_Loop4_2Model(S);
}

static void sf_opaque_set_sim_state_c11_Control_Loop4_2Model(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_Control_Loop4_2Model(S, st);
}

static void sf_opaque_terminate_c11_Control_Loop4_2Model(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Control_Loop4_2Model_optimization_info();
    }

    finalize_c11_Control_Loop4_2Model((SFc11_Control_Loop4_2ModelInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_Control_Loop4_2Model
    ((SFc11_Control_Loop4_2ModelInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Control_Loop4_2Model(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_Control_Loop4_2Model
      ((SFc11_Control_Loop4_2ModelInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Control_Loop4_2Model_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3430956663U));
  ssSetChecksum1(S,(3706368706U));
  ssSetChecksum2(S,(801728704U));
  ssSetChecksum3(S,(2258184659U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Control_Loop4_2Model(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_Control_Loop4_2Model(SimStruct *S)
{
  SFc11_Control_Loop4_2ModelInstanceStruct *chartInstance;
  chartInstance = (SFc11_Control_Loop4_2ModelInstanceStruct *)utMalloc(sizeof
    (SFc11_Control_Loop4_2ModelInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Control_Loop4_2ModelInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Control_Loop4_2Model;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Control_Loop4_2Model;
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

void c11_Control_Loop4_2Model_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Control_Loop4_2Model(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Control_Loop4_2Model(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Control_Loop4_2Model_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
