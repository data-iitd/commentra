
#include <iostream>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    int a, b, sum = 0;
    cin >> a >> b;

    // Loop runs twice, each time adding the larger of the two numbers to sum
    // and decrementing that number by 1
    for (int i = 0; i < 2; i++) {
        if (a >= b) {
            sum += a;
            a--;
        } else {
            sum += b;
            b--;
        }
    }

    // Print the final sum to the console
    cout << sum << endl;
    return 0;
}

