
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double input;
    cin >> input;
    double countOdd = round(input / 2);
    double result = countOdd / input;
    cout << fixed << setprecision(10) << result << endl;
    return 0;
}

