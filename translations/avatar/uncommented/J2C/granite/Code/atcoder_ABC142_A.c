
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    double input;
    scanf("%lf", &input);
    double countOdd = round(input / 2);
    double result = countOdd / input;
    printf("%.10lf\n", result);
    return 0;
}
//END-OF-CODE