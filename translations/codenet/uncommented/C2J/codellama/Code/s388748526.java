#include <stdio.h>
#include <math.h>

public class Main {
    public static void main(String[] args) {
        double r;
        scanf("%lf", &r);
        printf("%lf %lf\n", r * r * M_PI, 2 * M_PI * r);
    }
}

