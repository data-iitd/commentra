#include <iostream> // Including the iostream library for input and output
#include <cctype>   // Including cctype for character classification
#include <string>   // Including string library for string manipulation

using namespace std;

int main() {
    // Prompting the user to enter a word
    string word;
    cin >> word; // Reading input from the user

    // Initializing counters for uppercase and lowercase letters
    int uppercase = 0;
    int lowercase = 0;

    // Looping through each character in the input word
    for (char ch : word) {
        // Checking if the character is uppercase
        if (isupper(ch)) {
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }

    // Comparing the counts of uppercase and lowercase letters
    if (uppercase > lowercase) {
        // If there are more uppercase letters, print the word in uppercase
        cout << word << endl;
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        cout << word << endl;
    } else {
        // If the counts are equal, print the word in lowercase
        cout << word << endl;
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
