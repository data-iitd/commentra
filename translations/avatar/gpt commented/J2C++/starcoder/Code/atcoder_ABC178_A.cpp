#include <iostream>
using namespace std;

int main() {
    // Creating a Scanner object to read input from the console
    cin >> x;
    
    // Using a ternary operator to determine the boolean value based on the input
    bool bool = x == 1? true : false;
    
    // Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
    int result =!bool? 1 : 0;
    
    // Printing the result to the console
    cout << result << endl;
    
    // Flushing the output stream to ensure all data is written out
    cout.flush();
}

