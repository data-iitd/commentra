
#include <iostream>

using namespace std;

int main() {
    // Declaring a variable 'data' of type 'int' to read user input
    int data;

    // Reading user input and storing it in the 'data' variable
    cin >> data;

    // Declaring a variable'result' of type 'int' to store the result
    int result;

    // Assigning the value of 'data' cubed to the'result' variable
    result = data * data * data;

    // Printing the result using the 'Printf' function from 'fmt' package
    cout << result << endl; // Printing the result with format specifier '%d' and newline character '\n'
}

