

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    // Read the first integer from input
    int a;
    cin >> a;
    // Read the second integer from input
    int b;
    cin >> b;

    // Perform addition of the two integers
    int ret = a + b;

    // Check if the result is less than the difference between the two integers
    if (ret < (a - b)) {
        ret = a - b;
    }
    // Check if the updated result is less than the product of the two integers
    if (ret < (a * b)) {
        ret = a * b;
    }

    // Print the final result
    cout << ret << endl;

    return 0;
}

