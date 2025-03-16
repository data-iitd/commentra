
#include <iostream>  // Importingiostream for input/output operations
#include <string>    // Importing string for string manipulation

using namespace std;

int main() {
    string input;  // Declaring a string variable to store the input
    getline(cin, input);  // Reading input from the console and storing it in the input variable

    int result = 0;  // Initializing a variable to store the count of non-zero elements
    stringstream ss(input);  // Creating a stringstream object to tokenize the input string

    string token;  // Declaring a string variable to store each token
    while (getline(ss, token,'')) {  // Tokenizing the input string using space as the delimiter
        result += 1;  // Incrementing the result for each non-zero token
        if (token == "0") break;  // Breaking the loop if a zero is encountered
    }

    cout << result << endl;  // Printing the result to the console

    return 0;
}
