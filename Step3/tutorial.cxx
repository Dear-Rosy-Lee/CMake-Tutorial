#include "MathFunctions.h"
#include <cstdio>
#include <cstdlib>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout, "Usage: %s number\n", argv[0]);
        return 1;
    }
    float inputValue = atof(argv[1]);
    float outputValue = MathFunctions::sqrt(inputValue);
    fprintf(stdout, "The square root of %g is %g\n", inputValue, outputValue);
    return 0;
}