#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    string str; // Declaring a string variable
    cin >> str; // Reading the first line of input as a string
    long k; // Declaring a long variable
    cin >> k; // Reading the second line of input as a long integer
    int n = str.length(); // Finding the length of the string

    for (int i = 0; i < k; i++) { // Starting a for loop to iterate through the string up to the given limit 'k'
        if (str[i] == '1') { // Checking if the current character is '1'
            if (i == k - 1) { // Checking if the current index is the last index of the limit 'k'
                cout << 1 << endl; // If yes, print '1' and exit the function
                return 0; // Exit the function
            }
        } else {
            cout << str[i] << endl; // If the current character is not '1', print it to the console
            return 0; // Exit the function as soon as a non-'1' character is found
        }
    }
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
