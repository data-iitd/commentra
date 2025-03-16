
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int denominator = x2 - x1;
    int numerator = y2 - y1;

    double quotient;

    if (denominator!= 0) {
        quotient = (double) numerator / denominator;
    }

    if (numerator == 0) {
        int d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        x2 += d;
        x1 += d;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    if (denominator == 0) {
        y2 += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        y1 += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    if (quotient == 1) {
        x2 = x1;
        y3 = y2;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    if (quotient == -1) {
        x1 = x2;
        y3 = y1;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    if (denominator!= 0 && denominator!= 1 && denominator!= -1 && quotient!= 1 && quotient!= -1) {
        cout << -1 << endl;
    }

    return 0;
}
