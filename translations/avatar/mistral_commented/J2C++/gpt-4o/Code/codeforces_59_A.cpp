#include <iostream>  // Including the iostream library for input and output
#include <cctype>    // Including cctype for character classification
#include <string>    // Including string library for string manipulation

using namespace std;  // Using the standard namespace

int main() {  // Main function, entry point of the program
    string word;  // Declaring a string variable to hold the input word
    cin >> word;  // Reading the first word as input from the user

    int uppercase = 0;  // Initializing a counter for uppercase characters
    int lowercase = 0;  // Initializing a counter for lowercase characters

    for (int i = 0; i < word.length(); i++) {  // Iterating through each character in the word
        char ch = word[i];  // Assigning the character at the current index to a char variable

        if (isupper(ch)) {  // Checking if the character is uppercase
            uppercase++;  // Incrementing the uppercase counter
        } else {
            lowercase++;  // Incrementing the lowercase counter
        }
    }

    if (uppercase > lowercase) {  // Checking if there are more uppercase characters than lowercase characters
        cout << word;  // Printing the word in uppercase if condition is true
        for (char &c : word) c = toupper(c);  // Convert to uppercase
        cout << endl;  // New line after output
    } else if (lowercase > uppercase) {  // Checking if there are more lowercase characters than uppercase characters
        cout << word;  // Printing the word in lowercase if condition is true
        for (char &c : word) c = tolower(c);  // Convert to lowercase
        cout << endl;  // New line after output
    } else {  // If both uppercase and lowercase characters are equal
        for (char &c : word) c = tolower(c);  // Convert to lowercase
        cout << word << endl;  // Printing the word in lowercase if both conditions are false
    }

    return 0;  // Returning 0 to indicate successful completion
}

// <END-OF-CODE>
