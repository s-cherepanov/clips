   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*            CLIPS Version 6.40  01/06/16             */
   /*                                                     */
   /*             BASIC MATH FUNCTIONS MODULE             */
   /*******************************************************/

/*************************************************************/
/* Purpose:                                                  */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*      6.30: Support for long long integers.                */
/*                                                           */
/*            Converted API macros to function calls.        */
/*                                                           */
/*************************************************************/

#ifndef _H_bmathfun

#define _H_bmathfun

#ifndef _H_evaluatn
#include "evaluatn.h"
#endif

   void                    BasicMathFunctionDefinitions(void *);
   void                    AdditionFunction(void *,DATA_OBJECT_PTR);
   void                    MultiplicationFunction(void *,DATA_OBJECT_PTR);
   void                    SubtractionFunction(void *,DATA_OBJECT_PTR);
   void                    DivisionFunction(void *,DATA_OBJECT_PTR);
   long long               DivFunction(void *);
   bool                    SetAutoFloatDividendCommand(void *);
   bool                    GetAutoFloatDividendCommand(void *);
   bool                    EnvGetAutoFloatDividend(void *);
   bool                    EnvSetAutoFloatDividend(void *,int);
   long long               IntegerFunction(void *);
   double                  FloatFunction(void *);
   void                    AbsFunction(void *,DATA_OBJECT_PTR);
   void                    MinFunction(void *,DATA_OBJECT_PTR);
   void                    MaxFunction(void *,DATA_OBJECT_PTR);

#if ALLOW_ENVIRONMENT_GLOBALS

   bool                    GetAutoFloatDividend(void);
   bool                    SetAutoFloatDividend(int);

#endif

#endif




