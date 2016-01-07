   /*******************************************************/
   /*      "C" Language Integrated Production System      */
   /*                                                     */
   /*            CLIPS Version 6.40  01/06/16             */
   /*                                                     */
   /*          LOGICAL DEPENDENCIES HEADER FILE           */
   /*******************************************************/

/*************************************************************/
/* Purpose: Provide support routines for managing truth      */
/*   maintenance using the logical conditional element.      */
/*                                                           */
/* Principal Programmer(s):                                  */
/*      Gary D. Riley                                        */
/*                                                           */
/* Contributing Programmer(s):                               */
/*                                                           */
/* Revision History:                                         */
/*                                                           */
/*      6.24: Removed LOGICAL_DEPENDENCIES compilation flag. */
/*                                                           */
/*            Renamed BOOLEAN macro type to intBool.         */
/*                                                           */
/*            Rule with exists CE has incorrect activation.  */
/*            DR0867                                         */
/*                                                           */
/*      6.30: Added support for hashed memories.             */
/*                                                           */
/*************************************************************/

#ifndef _H_lgcldpnd

#define _H_lgcldpnd

struct dependency
  {
   void *dPtr;
   struct dependency *next;
  };

#ifndef _H_match
#include "match.h"
#endif
#ifndef _H_pattern
#include "pattern.h"
#endif

   bool                           AddLogicalDependencies(void *,struct patternEntity *,bool);
   void                           RemoveEntityDependencies(void *,struct patternEntity *);
   void                           RemovePMDependencies(void *,struct partialMatch *);
   void                           DestroyPMDependencies(void *,struct partialMatch *);
   void                           RemoveLogicalSupport(void *,struct partialMatch *);
   void                           ForceLogicalRetractions(void *);
   void                           Dependencies(void *,struct patternEntity *);
   void                           Dependents(void *,struct patternEntity *);
   void                           DependenciesCommand(void *);
   void                           DependentsCommand(void *);
   void                           ReturnEntityDependencies(void *,struct patternEntity *);
   struct partialMatch           *FindLogicalBind(struct joinNode *,struct partialMatch *);

#endif /* _H_lgcldpnd */





