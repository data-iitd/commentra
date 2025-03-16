#include <iostream>
using namespace std;

int main() {
    // Declaring variables a, b, c, x, and sum of integer data type
    int a, b, c, x, sum = 0;

    // Reading input values for variables a, b, c, and x from the user
    cin >> a >> b >> c >> x;

    // Initializing a nested for loop to iterate through the possible combinations of i, j, and k
    for (int i = 0; i <= a; i++) { // for i from 0 to a
        for (int j = 0; j <= b; j++) { // for j from 0 to b
            for (int k = 0; k <= c; k++) { // for k from 0 to c
                // Checking if the sum of i, j, and k multiplied by 50, 100, and 50 respectively equals x
                if (500 * i + 100 * j + 50 * k == x) {
                    sum++; // Incrementing the sum variable if the condition is true
                }
            }
        }
    }

    // Printing the final value of sum to the console
    cout << sum << endl;

    // End of the code
    return 0;
}

