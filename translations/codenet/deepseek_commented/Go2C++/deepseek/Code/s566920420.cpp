#include <iostream>
using namespace std;

int main() {
    // Declare an integer variable 'a' to store the user input
    int a;
    
    // Read an integer input from the user and store it in 'a'
    cin >> a;
    
    // Print the result of the expression 'a + a*a + a*a*a'
    cout << a + a*a + a*a*a << endl;
    
    return 0;
}

