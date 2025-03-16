#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Read two values from input: one as an integer and the other as a float in string format
    string sa, sb;
    cin >> sa >> sb;

    // Convert the first value to an integer
    int a = stoi(sa);

    // Convert the second value to an integer representing cents (by multiplying by 100)
    int b = static_cast<int>(stof(sb) * 100 + 0.1);

    // Calculate and print the product of a and b, divided by 100 to get the final result
    cout << (a * b) / 100 << endl;

    return 0;
}

// <END-OF-CODE>
