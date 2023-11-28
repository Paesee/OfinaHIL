// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------


#ifdef __cplusplus
#include <limits>

extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

// x86 libraries:
#include "../include/sp_functions_dev0.h"


#ifdef __cplusplus
}
#endif


#include "GeneralPID.h"

// ----------------------------------------------------------------------------------------                // generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif

// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: custom_consts.template----------------------------------------

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines






























struct _controlador_pid__GeneralPID {
    float  setpoint ;

    float  sampling_time ;

    float  KP ;

    float  KI ;

    float  KD ;

    float  K1 ;

    float  K2 ;

    float  K3 ;

    float  K1_anti_windup ;

    float  K2_anti_windup ;

    float  K3_anti_windup ;

    float  error_n1 ;

    float  error_n2 ;

    float  output_n1 ;

    float  output_n2 ;

    float  max_output ;

    float  min_output ;
}  ;
struct _controlador_pid__GeneralPID  _controlador_pid__pid;
float  _controlador_pid__acao_calculada = 0;





//@cmp.def.end


//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables



//@cmp.var.start
// variables
double _il1_ia1__out;
double _iload_ia1__out;
double _rate_transition1_output__out;
double _rate_transition2_output__out;
double _scada_sp_trigger__out;
double _scada_enable__out;
double _scada_kd__out;
double _scada_ki__out;
double _scada_kp__out;
double _scada_s1__out;
double _scada_s2__out;
double _scada_s3__out;
double _scada_vref__out;
double _vc_va1__out;
float _feedback_sp_trigger__tmp;
float _feedback_enable__tmp;
float _feedback_kd__tmp;
float _feedback_ki__tmp;
float _feedback_kp__tmp;
float _feedback_s1__tmp;
float _feedback_s2__tmp;
float _feedback_s3__tmp;
double _controlador_pid__in_enabled;
double _controlador_pid__in_kd;
double _controlador_pid__in_ki;
double _controlador_pid__in_kp;
double _controlador_pid__in_vc;
double _controlador_pid__in_vref;

double _controlador_pid__out_acao_controle;
//@cmp.var.end

//@cmp.svar.start
// state variables
double _rate_transition1_output__state;
double _rate_transition2_output__state;

//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
} __attribute__((__packed__)) tunable_params;

void *tunable_params_dev0_cpu0_ptr = &tunable_params;

// Dll function pointers
#if defined(_WIN64)
#else
// Define handles for loading dlls
#endif








// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif
    //@cmp.init.block.start
    _rate_transition1_output__state =  0.0;
    _rate_transition2_output__state =  0.0;
    HIL_OutAO(0x2002, 0.0f);
    HIL_OutAO(0x2003, 0.0f);
    HIL_OutAO(0x2001, 0.0f);
    {
        PID_init ( & _controlador_pid__pid , 0.0001 , 0 , 0 , 0 ) ;
        PID_setMatlabGains ( & _controlador_pid__pid , 0.3062 , - 0.3698 , 0.08393 ) ;
        PID_setBoundaries ( & _controlador_pid__pid , 100 , - 100 ) ;
        _controlador_pid__acao_calculada = 0 ;
    }
    HIL_OutAO(0x2004, 0.0f);
    HIL_OutAO(0x2000, 0.0f);
    HIL_OutFloat(137101312, 0.0);
    //@cmp.init.block.end
}


// Dll function pointers and dll reload function
#if defined(_WIN64)
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}

#else
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}
#endif

void load_fmi_libraries_user_sp_cpu0_dev0(void) {
#if defined(_WIN64)
#else
#endif
}


void ReInit_sp_scope_user_sp_cpu0_dev0() {
    // initialise SP Scope buffer pointer
}
// generated using template: common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Il1.Ia1
    _il1_ia1__out = (HIL_InFloat(0xc80000 + 0x3));
    // Generated from the component: Iload.Ia1
    _iload_ia1__out = (HIL_InFloat(0xc80000 + 0x4));
    // Generated from the component: Rate Transition1.Output
    _rate_transition1_output__out = _rate_transition1_output__state;
    // Generated from the component: Rate Transition2.Output
    _rate_transition2_output__out = _rate_transition2_output__state;
    // Generated from the component: SCADA_SP_trigger
    _scada_sp_trigger__out = XIo_InFloat(0x55000100);
    // Generated from the component: SCADA_kd
    _scada_kd__out = XIo_InFloat(0x55000108);
    // Generated from the component: SCADA_ki
    _scada_ki__out = XIo_InFloat(0x5500010c);
    // Generated from the component: SCADA_kp
    _scada_kp__out = XIo_InFloat(0x55000110);
    // Generated from the component: SCADA_vref
    _scada_vref__out = XIo_InFloat(0x55000120);
    // Generated from the component: Vc.Va1
    _vc_va1__out = (HIL_InFloat(0xc80000 + 0x2));
    // Generated from the component: SYS_il1
    HIL_OutAO(0x2002, (float)_il1_ia1__out);
    // Generated from the component: SYS_iload
    HIL_OutAO(0x2003, (float)_iload_ia1__out);
    // Generated from the component: FEEDBACK_SP_trigger
    HIL_OutInt32(0xf00400, _scada_sp_trigger__out != 0x0);
    // Generated from the component: FEEDBACK_kd
    HIL_OutInt32(0xf00402, _scada_kd__out != 0x0);
    // Generated from the component: FEEDBACK_ki
    HIL_OutInt32(0xf00403, _scada_ki__out != 0x0);
    // Generated from the component: FEEDBACK_kp
    HIL_OutInt32(0xf00404, _scada_kp__out != 0x0);
    // Generated from the component: FEEDBACK_vref
    HIL_OutAO(0x2001, (float)_scada_vref__out);
    // Generated from the component: Rate Transition1.Input
    _rate_transition1_output__state = _scada_vref__out;
    // Generated from the component: Controlador PID
    _controlador_pid__in_enabled = _rate_transition2_output__out;
    _controlador_pid__in_kd = _scada_kd__out;
    _controlador_pid__in_ki = _scada_ki__out;
    _controlador_pid__in_kp = _scada_kp__out;
    _controlador_pid__in_vc = _vc_va1__out;
    _controlador_pid__in_vref = _rate_transition1_output__out;
    {
        if ( _controlador_pid__in_enabled )     {
            PID_setSetpoint ( & _controlador_pid__pid , _controlador_pid__in_vref ) ;
            _controlador_pid__acao_calculada = PID_execute ( & _controlador_pid__pid , _controlador_pid__in_vc ) ;
            _controlador_pid__out_acao_controle = _controlador_pid__acao_calculada ;
        }
        else     {
            _controlador_pid__out_acao_controle = 0 ;
        }
    }
    // Generated from the component: SYS_vc
    HIL_OutAO(0x2004, (float)_vc_va1__out);
    // Generated from the component: FEEDBACK_acao
    HIL_OutAO(0x2000, (float)_controlador_pid__out_acao_controle);
    // Generated from the component: Vcc.Vs1
    HIL_OutFloat(137101312, (float) _controlador_pid__out_acao_controle);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Controlador PID
    //@cmp.update.block.end
}
void TimerCounterHandler_1_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_1");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: SCADA_enable
    _scada_enable__out = XIo_InFloat(0x55000104);
    // Generated from the component: SCADA_s1
    _scada_s1__out = XIo_InFloat(0x55000114);
    // Generated from the component: SCADA_s2
    _scada_s2__out = XIo_InFloat(0x55000118);
    // Generated from the component: SCADA_s3
    _scada_s3__out = XIo_InFloat(0x5500011c);
    // Generated from the component: FEEDBACK_enable
    HIL_OutInt32(0xf00401, _scada_enable__out != 0x0);
    // Generated from the component: Rate Transition2.Input
    _rate_transition2_output__state = _scada_enable__out;
    // Generated from the component: FEEDBACK_s1
    HIL_OutInt32(0xf00405, _scada_s1__out != 0x0);
    // Generated from the component: S1.CTC_Wrapper
    if (_scada_s1__out == 0x0) {
        HIL_OutInt32(0x8240480, 0x0);
    }
    else {
        HIL_OutInt32(0x8240480, 0x1);
    }
    // Generated from the component: FEEDBACK_s2
    HIL_OutInt32(0xf00406, _scada_s2__out != 0x0);
    // Generated from the component: S2.CTC_Wrapper
    if (_scada_s2__out == 0x0) {
        HIL_OutInt32(0x8240481, 0x0);
    }
    else {
        HIL_OutInt32(0x8240481, 0x1);
    }
    // Generated from the component: FEEDBACK_s3
    HIL_OutInt32(0xf00407, _scada_s3__out != 0x0);
    // Generated from the component: S3.CTC_Wrapper
    if (_scada_s3__out == 0x0) {
        HIL_OutInt32(0x8240482, 0x0);
    }
    else {
        HIL_OutInt32(0x8240482, 0x1);
    }
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------