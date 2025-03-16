
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    double input;
    double countOdd;
    double result;

    scanf("%lf", &input);
    countOdd = round(input / 2);
    result = countOdd / input;
    printf("%.10lf\n", result);

    return 0;
}

