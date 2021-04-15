// Exclusions de la couverture de code:
#include "CodeCoverage_bugfix.h"
#ifdef ExcludeSourceFromCodeCoverage
ExcludeSourceFromCodeCoverage(ProgramFilesFilter1, L"*\\Program Files (x86)\\*")
ExcludeSourceFromCodeCoverage(ProgramFilesFilter2, L"*\\Program Files\\*")
ExcludeSourceFromCodeCoverage(SdkFilesFilter1, L"sdk\\*")
ExcludeSourceFromCodeCoverage(SharedFilesFilter1, L"shared\\*")
ExcludeSourceFromCodeCoverage(BoostFilesFilter1, L"*\\boost\\*")
ExcludeSourceFromCodeCoverage(GtestFilesFilter1, L"*\\googletest\\*")
ExcludeSourceFromCodeCoverage(GtestFilesFilter2, L"*\\gtest\\*")
ExcludeSourceFromCodeCoverage(GslFilesFilter1, L"*\\gsl\\*")
ExcludeSourceFromCodeCoverage(ItertoolsFilesFilter1, L"*\\cppitertools\\*")
ExcludeSourceFromCodeCoverage(VcpkgFilesFilter1, L"*\\vcpkg*\\*")
ExcludeSourceFromCodeCoverage(TestsFilesFilter1, L"*\\tests\\*")
#endif
