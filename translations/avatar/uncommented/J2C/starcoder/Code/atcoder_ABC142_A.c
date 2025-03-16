#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double input;
    double countOdd;
    double result;

    if (argc!= 2) {
        printf("Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    input = atof(argv[1]);
    countOdd = round(input / 2);
    result = countOdd / input;
    printf("%.10f\n", result);

    return 0;
}

