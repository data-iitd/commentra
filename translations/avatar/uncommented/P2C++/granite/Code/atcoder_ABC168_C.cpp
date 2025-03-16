
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int a, b, h, m;
    scanf("%d %d %d %d", &a, &b, &h, &m);
    double C = abs(360.0 / 60 * m - 360.0 / 12 * h - 360.0 / 12 / 60 * m);
    if (C > 180) {
        C = 360 - C;
    }
    double cosC = cos(C * M_PI / 180);
    printf("%.10f\n", sqrt(a * a + b * b - 2 * a * b * cosC));
    return 0;
}

