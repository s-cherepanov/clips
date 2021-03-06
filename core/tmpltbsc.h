   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*            CLIPS Version 6.40  01/06/16             */
   /*                                                     */
   /*       DEFTEMPLATE BASIC COMMANDS HEADER FILE        */
   /*******************************************************/

/*************************************************************/
/* Purpose: Implements core commands for the deftemplate     */
/*   construct such as clear, reset, save, undeftemplate,    */
/*   ppdeftemplate, list-deftemplates, and                   */
/*   get-deftemplate-list.                                   */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*      Brian L. Dantes                                      */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*            Changed name of variable log to logName        */
/*            because of Unix compiler warnings of shadowed  */
/*            definitions.                                   */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*            Corrected code to remove compiler warnings     */
/*            when ENVIRONMENT_API_ONLY flag is set.         */
/*                                                           */
/*      6.30: Removed conditional code for unsupported       */
/*            compilers/operating systems (IBM_MCW,          */
/*            MAC_MCW, and IBM_TBC).                         */
/*                                                           */
/*            Added const qualifiers to remove C++           */
/*            deprecation warnings.                          */
/*                                                           */
/*            Converted API macros to function calls.        */
/*                                                           */
/*************************************************************/

#ifndef _H_tmpltbsc

#pragma once

#define _H_tmpltbsc

#include "evaluatn.h"

   void                           DeftemplateBasicCommands(void *);
   void                           UndeftemplateCommand(UDFContext *,CLIPSValue *);
   bool                           EnvUndeftemplate(void *,void *);
   void                           GetDeftemplateListFunction(UDFContext *,CLIPSValue *);
   void                           EnvGetDeftemplateList(void *,DATA_OBJECT_PTR,void *);
   void                           DeftemplateModuleFunction(UDFContext *,CLIPSValue *);
#if DEBUGGING_FUNCTIONS
   void                           PPDeftemplateCommand(UDFContext *,CLIPSValue *);
   int                            PPDeftemplate(void *,const char *,const char *);
   void                           ListDeftemplatesCommand(UDFContext *,CLIPSValue *);
   void                           EnvListDeftemplates(void *,const char *,void *);
   bool                           EnvGetDeftemplateWatch(void *,void *);
   void                           EnvSetDeftemplateWatch(void *,bool,void *);
   bool                           DeftemplateWatchAccess(void *,int,bool,struct expr *);
   bool                           DeftemplateWatchPrint(void *,const char *,int,struct expr *);
#endif

#endif /* _H_tmpltbsc */


