/*
 * flinting: FLINT in GAP
 */

#include "src/compiled.h"          /* GAP headers */

Int T_FLINT;
Obj TYPE_FLINTOBJ;

Obj TypeFlintObj(Obj o)
{
    return TYPE_FLINTOBJ;
}

/* Memory management */
Obj NewFlintObj(Obj self, Obj c)
{
    Obj o;

    if(!IS_INTOBJ(c)) {
        ErrorQuit( "Usage: NewFlintObj(integer)", 0L, 0L);
    }
    o = NewBag(T_FLINT, 2 * sizeof(Obj));

    return o;
}

void MarkFlintObj(Bag o)
{
}

void SweepFlintObj(Bag *src, Bag *dst, UInt len)
{
}

void FreeFlintObj(Obj o)
{
}

typedef Obj (* GVarFunc)(/*arguments*/);

#define GVAR_FUNC_TABLE_ENTRY(srcfile, name, nparam, params) \
  {#name, nparam, \
   params, \
   (GVarFunc)name, \
   srcfile ":Func" #name }

// Table of functions to export
static StructGVarFunc GVarFuncs [] = {
    GVAR_FUNC_TABLE_ENTRY("flinting.c", NewFlintObj, 1, "type"),

	{ 0 } /* Finish with an empty entry */

};

/******************************************************************************
*F  InitKernel( <module> )  . . . . . . . . initialise kernel data structures
*/
static Int InitKernel( StructInitInfo *module )
{
    ImportGVarFromLibrary("TypeFlintObj", &TYPE_FLINTOBJ);
    T_FLINT = RegisterPackageTNUM("FlintingTNUM", TypeFlintObj);

    InitFreeFuncBag(T_FLINT, FreeFlintObj);
    InitMarkFuncBags(T_FLINT, MarkFlintObj);
    InitSweepFuncBags(T_FLINT, SweepFlintObj);   
 
    /* init filters and functions                                          */
    InitHdlrFuncsFromTable( GVarFuncs );

    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitLibrary( <module> ) . . . . . . .  initialise library data structures
*/
static Int InitLibrary( StructInitInfo *module )
{
    /* init filters and functions */
    InitGVarFuncsFromTable( GVarFuncs );

    /* return success                                                      */
    return 0;
}

/******************************************************************************
*F  InitInfopl()  . . . . . . . . . . . . . . . . . table of init functions
*/
static StructInitInfo module = {
 /* type        = */ MODULE_DYNAMIC,
 /* name        = */ "flinting",
 /* revision_c  = */ 0,
 /* revision_h  = */ 0,
 /* version     = */ 0,
 /* crc         = */ 0,
 /* initKernel  = */ InitKernel,
 /* initLibrary = */ InitLibrary,
 /* checkInit   = */ 0,
 /* preSave     = */ 0,
 /* postSave    = */ 0,
 /* postRestore = */ 0
};

StructInitInfo *Init__Dynamic( void )
{
    return &module;
}
