
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double input;
    cin >> input;

    double countOdd = round(input / 2);

    double result = countOdd / input;

    cout << setprecision(10) << fixed << result << endl;

    return 0;
}

