   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*             CLIPS Version 6.30  07/25/14            */
   /*                                                     */
   /*         DEFFACTS BASIC COMMANDS HEADER FILE         */
   /*******************************************************/

/*************************************************************/
/* Purpose: Implements core commands for the deffacts        */
/*   construct such as clear, reset, save, undeffacts,       */
/*   ppdeffacts, list-deffacts, and get-deffacts-list.       */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*      Brian L. Dantes                                      */
/*                                                           */
/* Revision History:                                         */
/*      6.23: Corrected compilation errors for files         */
/*            generated by constructs-to-c. DR0861           */
/*                                                           */
/*      6.24: Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*      6.30: Added const qualifiers to remove C++           */
/*            deprecation warnings.                          */
/*                                                           */
/*************************************************************/

#ifndef _H_dffctbsc
#define _H_dffctbsc

#ifndef _H_evaluatn
#include "evaluatn.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef _DFFCTBSC_SOURCE_
#define LOCALE
#else
#define LOCALE extern
#endif

#define GetDeffactsList(a,b) EnvGetDeffactsList(GetCurrentEnvironment(),a,b)
#define ListDeffacts(a,b) EnvListDeffacts(GetCurrentEnvironment(),a,b)
#define Undeffacts(a) EnvUndeffacts(GetCurrentEnvironment(),a)

   LOCALE void                           DeffactsBasicCommands(void *);
   LOCALE void                           UndeffactsCommand(void *);
   LOCALE intBool                        EnvUndeffacts(void *,void *);
   LOCALE void                           GetDeffactsListFunction(void *,DATA_OBJECT_PTR);
   LOCALE void                           EnvGetDeffactsList(void *,DATA_OBJECT_PTR,void *);
   LOCALE void                          *DeffactsModuleFunction(void *);
   LOCALE void                           PPDeffactsCommand(void *);
   LOCALE int                            PPDeffacts(void *,const char *,const char *);
   LOCALE void                           ListDeffactsCommand(void *);
   LOCALE void                           EnvListDeffacts(void *,const char *,void *);

#endif

