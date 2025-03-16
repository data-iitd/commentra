

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {  // Base case: factorial of 0 is 1
        return 1;
    } else {
        return n * factorial(n - 1);  // Recursive case: n * factorial of (n - 1)
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    int result = factorial(number);  // Calculate the factorial of the input number
    cout << "Factorial of " << number << " is " << result << endl;
    return 0;
}

