#include <iostream> // Including the iostream library for input and output
#include <string>   // Including the string library for string manipulation

using namespace std; // Using the standard namespace

void cout(const string& str) { // Defining a function named cout that takes a string argument and prints it to the console
    std::cout << str; // Printing the given string to the console
}

int main() { // Defining the main function that is the entry point of the program
    int n; // Declaring an integer variable named n
    cin >> n; // Reading an integer value from the console and assigning it to the variable n
    cin.ignore(); // Consuming the newline character left after reading an integer value

    string str; // Declaring a string variable named str
    getline(cin, str); // Reading a line of text from the console and assigning it to the variable str

    string a = ""; // Initializing an empty string a

    for (int i = 0; i < n / 2; i++) { // Starting a for loop that iterates n/2 times
        a += str[i]; // Appending the character at the current index of str to the variable a
    }

    if (str == a + a) { // Starting an if statement to check if the given string is a palindrome
        cout("Yes\n"); // Printing "Yes" to the console if the given string is a palindrome
    } else {
        cout("No\n"); // Printing "No" to the console if the given string is not a palindrome
    }

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
