#
# flinting: FLINT in GAP
#
# Declarations
#

DeclareCategory("IsFL_Object", IsObject);

FLFamily := NewFamily("FL_ZmodnZ");

DeclareCategory("IsFL_ZmodnZVec", IsFL_Object and IsHomogeneousList);
DeclareCategory("IsFL_ZmodnZMat", IsFL_Object and IsMatrixObj);

BindGlobal("TypeFlintObj", NewType(FLFamily, IsFL_ZmodnZVec));


