/* Include files */

#include "Control_Loop4_2Model_sfun.h"
#include "Control_Loop4_2Model_sfun_debug_macros.h"
#include "c1_Control_Loop4_2Model.h"
#include "c2_Control_Loop4_2Model.h"
#include "c3_Control_Loop4_2Model.h"
#include "c4_Control_Loop4_2Model.h"
#include "c5_Control_Loop4_2Model.h"
#include "c6_Control_Loop4_2Model.h"
#include "c7_Control_Loop4_2Model.h"
#include "c8_Control_Loop4_2Model.h"
#include "c9_Control_Loop4_2Model.h"
#include "c10_Control_Loop4_2Model.h"
#include "c11_Control_Loop4_2Model.h"
#include "c12_Control_Loop4_2Model.h"
#include "c13_Control_Loop4_2Model.h"
#include "c14_Control_Loop4_2Model.h"
#include "c15_Control_Loop4_2Model.h"
#include "c16_Control_Loop4_2Model.h"
#include "c17_Control_Loop4_2Model.h"
#include "c18_Control_Loop4_2Model.h"
#include "c19_Control_Loop4_2Model.h"
#include "c20_Control_Loop4_2Model.h"
#include "c21_Control_Loop4_2Model.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Control_Loop4_2ModelMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void Control_Loop4_2Model_initializer(void)
{
}

void Control_Loop4_2Model_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Control_Loop4_2Model_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Control_Loop4_2Model_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_Control_Loop4_2Model_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1124200165U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2265559294U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3676239126U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2493831098U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(280984872U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1187233649U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1623908331U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3468313084U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c1_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c2_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c3_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c4_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c5_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c6_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c7_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c8_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c9_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c10_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c11_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c12_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c13_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c14_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c15_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c16_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c17_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c18_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c19_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c20_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_Control_Loop4_2Model_get_check_sum(mxArray *plhs[]);
          sf_c21_Control_Loop4_2Model_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3031367619U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4001028638U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3978939492U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(838979348U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3530053667U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(948006466U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4114649180U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2120378924U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Control_Loop4_2Model_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "qU3QVCJm3xNXVTB7h7qaeH") == 0) {
          extern mxArray *sf_c1_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "XkXTfwU3EFjVCGYPj9EpLC") == 0) {
          extern mxArray *sf_c2_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "O3YbjzikbNMRMC0ankXL9F") == 0) {
          extern mxArray *sf_c3_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "IZFkUZTmMCx1XRGJ2P2gF") == 0) {
          extern mxArray *sf_c4_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c4_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "1uWvMvl7PuvUR6mqM589dD") == 0) {
          extern mxArray *sf_c5_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "K4Kx84MIl52JcMVemU3SCC") == 0) {
          extern mxArray *sf_c6_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "z4kghk37k5iU9NPF0FGX2") == 0) {
          extern mxArray *sf_c7_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "sP7KdvLEeAubtSSJu6YkO") == 0) {
          extern mxArray *sf_c8_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c8_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "zVs3FoHi5HjTfl0fbsWdpE") == 0) {
          extern mxArray *sf_c9_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "3nl9RDLvlRBcQwPpH5lTSG") == 0) {
          extern mxArray *sf_c10_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "XqMxYLX5HviGtpN91obU0C") == 0) {
          extern mxArray *sf_c11_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "EzWTyfF2FCW8x0Jgwe2dVC") == 0) {
          extern mxArray *sf_c12_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c12_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "CxAKeY565ICstDjEYvCvqG") == 0) {
          extern mxArray *sf_c13_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c13_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "6H5l9MvmxBzqXMHEpvgU1D") == 0) {
          extern mxArray *sf_c14_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c14_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "VE9pbxyMrdkOPiq1ylBIvB") == 0) {
          extern mxArray *sf_c15_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "R8JSBdGkhnfuG8g45T53zF") == 0) {
          extern mxArray *sf_c16_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "ouUXfcEtVoBWR5ZbZyCHuB") == 0) {
          extern mxArray *sf_c17_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "iV8pEO5046CS1TG3tpwplC") == 0) {
          extern mxArray *sf_c18_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "BjjDSu0GWlCty7NfTwjOkC") == 0) {
          extern mxArray *sf_c19_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c19_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "5H3LD3L3TgFArjtzQYePGD") == 0) {
          extern mxArray *sf_c20_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "KHlm75bk0wAAE58YkH1UhH") == 0) {
          extern mxArray *sf_c21_Control_Loop4_2Model_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_Control_Loop4_2Model_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Control_Loop4_2Model_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_Control_Loop4_2Model_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Control_Loop4_2Model_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Control_Loop4_2Model_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "loNTX7MKS3tWN4opPkW78E") == 0) {
          extern mxArray *sf_c1_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c1_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "O9xmxdkB3vnfcuIEC54KZD") == 0) {
          extern mxArray *sf_c2_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c2_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "iwwqJCgQlsgRJf4iwlp8SF") == 0) {
          extern mxArray *sf_c3_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c3_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "XyvTXncbz1P178UGHdjXoB") == 0) {
          extern mxArray *sf_c4_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c4_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "54A2Vlgp8S6Dapuq8CPDdB") == 0) {
          extern mxArray *sf_c5_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c5_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "DFBHNWVsTCdJIHUmkjW9cE") == 0) {
          extern mxArray *sf_c6_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c6_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "PEKdEzUqBw5Zwx69rZyMyB") == 0) {
          extern mxArray *sf_c7_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c7_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "OxJ9EwGrUg4uvwuXACybYH") == 0) {
          extern mxArray *sf_c8_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c8_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "iBGfAsnF3c8jHAYXYRQ2WF") == 0) {
          extern mxArray *sf_c9_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c9_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "gYE1YFXCwxYDItsbrjMir") == 0) {
          extern mxArray *sf_c10_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c10_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sD3Sed2F4SwvIJpgEiAkfE") == 0) {
          extern mxArray *sf_c11_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c11_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "P1bnWUPT3fkzWuIoMcx5lD") == 0) {
          extern mxArray *sf_c12_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c12_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "MM06CiYj645YjGKsSVxkSD") == 0) {
          extern mxArray *sf_c13_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c13_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "Rf0R8enG7u2VSqWc7EunYG") == 0) {
          extern mxArray *sf_c14_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c14_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "2r1EGsOL8ttMoJu9DAfFMH") == 0) {
          extern mxArray *sf_c15_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c15_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "GzTt4g5WTpOZbIAInNz9BD") == 0) {
          extern mxArray *sf_c16_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c16_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "FBYoiBDKbgvWSjOcGRL8AH") == 0) {
          extern mxArray *sf_c17_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c17_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "ePuV7K1lmOJbpFKLCrsvPB") == 0) {
          extern mxArray *sf_c18_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c18_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "pEsnRnohT7CHd9ioFob0iB") == 0) {
          extern mxArray *sf_c19_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c19_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "eh53oiUbOucoNgGT07svWC") == 0) {
          extern mxArray *sf_c20_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c20_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "M3pyMHlc02RkLy1XSqQ0yC") == 0) {
          extern mxArray *sf_c21_Control_Loop4_2Model_third_party_uses_info(void);
          plhs[0] = sf_c21_Control_Loop4_2Model_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Control_Loop4_2Model_updateBuildInfo_args_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "loNTX7MKS3tWN4opPkW78E") == 0) {
          extern mxArray *sf_c1_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "O9xmxdkB3vnfcuIEC54KZD") == 0) {
          extern mxArray *sf_c2_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "iwwqJCgQlsgRJf4iwlp8SF") == 0) {
          extern mxArray *sf_c3_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c3_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "XyvTXncbz1P178UGHdjXoB") == 0) {
          extern mxArray *sf_c4_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c4_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "54A2Vlgp8S6Dapuq8CPDdB") == 0) {
          extern mxArray *sf_c5_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "DFBHNWVsTCdJIHUmkjW9cE") == 0) {
          extern mxArray *sf_c6_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c6_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "PEKdEzUqBw5Zwx69rZyMyB") == 0) {
          extern mxArray *sf_c7_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c7_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "OxJ9EwGrUg4uvwuXACybYH") == 0) {
          extern mxArray *sf_c8_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c8_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "iBGfAsnF3c8jHAYXYRQ2WF") == 0) {
          extern mxArray *sf_c9_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "gYE1YFXCwxYDItsbrjMir") == 0) {
          extern mxArray *sf_c10_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "sD3Sed2F4SwvIJpgEiAkfE") == 0) {
          extern mxArray *sf_c11_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "P1bnWUPT3fkzWuIoMcx5lD") == 0) {
          extern mxArray *sf_c12_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c12_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "MM06CiYj645YjGKsSVxkSD") == 0) {
          extern mxArray *sf_c13_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c13_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "Rf0R8enG7u2VSqWc7EunYG") == 0) {
          extern mxArray *sf_c14_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c14_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "2r1EGsOL8ttMoJu9DAfFMH") == 0) {
          extern mxArray *sf_c15_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "GzTt4g5WTpOZbIAInNz9BD") == 0) {
          extern mxArray *sf_c16_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c16_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "FBYoiBDKbgvWSjOcGRL8AH") == 0) {
          extern mxArray *sf_c17_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c17_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "ePuV7K1lmOJbpFKLCrsvPB") == 0) {
          extern mxArray *sf_c18_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c18_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "pEsnRnohT7CHd9ioFob0iB") == 0) {
          extern mxArray *sf_c19_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c19_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "eh53oiUbOucoNgGT07svWC") == 0) {
          extern mxArray *sf_c20_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c20_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "M3pyMHlc02RkLy1XSqQ0yC") == 0) {
          extern mxArray *sf_c21_Control_Loop4_2Model_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c21_Control_Loop4_2Model_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void Control_Loop4_2Model_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Control_Loop4_2ModelMachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Control_Loop4_2Model","sfun",0,21,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Control_Loop4_2ModelMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Control_Loop4_2ModelMachineNumber_,0);
}

void Control_Loop4_2Model_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Control_Loop4_2Model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Control_Loop4_2Model", "Control_Loop4_2Model");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Control_Loop4_2Model_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
