#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two variables to store the values of a and b
    int a, b;

    // Read two values from input: one as an integer and the other as a float in string format
    cin >> a >> b;

    // Convert the second value to an integer representing cents (by multiplying by 100)
    b = int(b * 100 + 0.1);

    // Calculate and print the product of a and b, divided by 100 to get the final result
    cout << a * b / 100 << endl;

    return 0;
}

