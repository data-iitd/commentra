
#include <stdio.h>
#include <math.h>

int main() {
    double input;
    scanf("%lf", &input);
    double countOdd = round(input / 2);
    double result = round(countOdd / input * pow(10, 10)) / pow(10, 10);
    printf("%.10lf\n", result);
    return 0;
}

