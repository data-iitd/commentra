#include <iostream>  // Including necessary I/O classes from the C++ standard library
#include <string>    // Including string class from the C++ standard library
#include <unordered_set> // Including unordered_set for storing unique strings
#include <algorithm> // Including algorithm for using std::min

using namespace std; // Using the standard namespace

int main() {
    // Declaring the main function, which is the entry point of the C++ application

    string arr; 
    getline(cin, arr); 
    // Reading the first line of input as a string and storing it in the 'arr' variable

    int N = arr.length(); 
    // Declaring and initializing the length of the string 'arr' in the variable 'N'

    unordered_set<string> set; 
    // Creating an empty unordered_set object to store unique strings

    int K; 
    cin >> K; 
    cin.ignore(); // To ignore the newline character after reading K
    // Reading the second line of input as an integer and storing it in the variable 'K'

    int res = 0; 
    // Declaring and initializing an integer variable 'res' to store the result

    for (int k = 0; k < K; k++) {
        // Starting a for loop that iterates 'K' times

        string input; 
        getline(cin, input); 
        // Reading a string as input and storing it in the 'input' variable

        int a = 0; 
        int b = 0; 
        // Declaring and initializing two integer variables 'a' and 'b' to count the occurrences of two different characters in the string 'arr'

        for (int i = 0; i < N; i++) {
            // Starting a nested for loop that iterates through each index of the string 'arr'

            if (arr[i] == input[0]) 
                a++;  // Incrementing the 'a' variable if the character at the current index matches the first character of the input string

            else if (arr[i] == input[1]) 
                b++;  // Incrementing the 'b' variable if the character at the current index matches the second character of the input string

            else {
                res += min(a, b);  // Adding the minimum of 'a' and 'b' to the 'res' variable if the current character is different from both characters in the input string
                a = b = 0;  // Resetting the 'a' and 'b' variables to zero
            }
        }

        res += min(a, b);  // Adding the minimum of 'a' and 'b' to the 'res' variable after the end of the outer for loop
    }

    cout << res << endl; 
    // Printing the final result to the standard output stream

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
