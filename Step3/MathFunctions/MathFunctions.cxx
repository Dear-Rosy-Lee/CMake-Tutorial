#include "MathFunctions.h"
#ifdef USE_MYMATH
#include "mysqrt.h"
#else
#include <cmath>
#endif
double MathFunctions::sqrt(double x) {
    #ifdef USE_MYMATH
        return mysqrt(x);
    #else
        return std::sqrt(x);
    #endif
}