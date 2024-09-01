#include "mysqrt.h"
double mysqrt(double x)
{
    if (x <= 0)
    {
        return 0;
    }

    double result;
    double xhalf = 0.5f * x;
    int i = *(int *)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(double *)&i;
    result = x * (1.5f - xhalf * x * x);
    return 1.0f / result;
}