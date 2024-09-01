#include "mysqrt.h"
#include <cmath> // for fabs

double mysqrt(double x)
{
    if (x <= 0) return 0;
    double result = x;
    double last_result;
    do {
        last_result = result;
        result = (result + x / result) / 2.0;
    } while (fabs(result - last_result) > 1e-6);
    return result;
}
