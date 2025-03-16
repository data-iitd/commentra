#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double input;
    scanf("%lf", &input);
    double countOdd = round(input / 2);
    double result = (countOdd / input);
    result = round(result * pow(10, 10));
    result = result / pow(10, 10);
    printf("%.10lf\n", result);
    return 0;
}

