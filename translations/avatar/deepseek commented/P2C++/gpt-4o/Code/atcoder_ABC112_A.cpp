#include <iostream>
using namespace std;

int main() {
    int age;  // Declare an integer variable `age`
    cin >> age;  // Taking an integer input for the variable `age`
    
    if (age == 1) {  // Checking if `age` is equal to 1
        cout << "Hello World" << endl;  // If `age` is 1, it prints "Hello World"
    } else {  // If `age` is not 1
        int a, b;  // Declare two integer variables `a` and `b`
        cin >> a >> b;  // Taking two integer inputs and assigning them to variables `a` and `b`
        cout << (a + b) << endl;  // Printing the sum of `a` and `b`
    }
    
    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
