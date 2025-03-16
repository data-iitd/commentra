#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double input, countOdd;
    scanf("%lf", &input);
    countOdd = round(input / 2);
    double result = countOdd / input;
    printf("%.10f\n", result);
    return 0;
}

