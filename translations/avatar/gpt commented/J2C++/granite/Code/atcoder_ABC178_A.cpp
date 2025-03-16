
#include <iostream> // Importing utility classes for input and output
#include <string> // Importing classes for input and output operations

using namespace std;

int main() {
    // Creating a string variable to store the input
    string input;
    
    // Reading a string input from the user
    getline(cin, input);
    
    // Using a ternary operator to determine the boolean value based on the input
    bool bool = input == "1"? true : false;
    
    // Setting the result based on the boolean value; if bool is false, result is 1, otherwise 0
    int result =!bool? 1 : 0;
    
    // Printing the result to the console
    cout << result << endl;
    
    return 0;
}

