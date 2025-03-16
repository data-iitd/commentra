
#include <iostream> // Including the necessary header file for input/output operations
#include <string> // Including the necessary header file for string operations

using namespace std; // Using the standard namespace for convenience

int main() {
    string word; // Declaring a string variable to store the input word
    cout << "Enter a word: "; // Displaying a prompt to the user to enter a word
    getline(cin, word); // Reading a single word from the user input
    
    int uppercase = 0; // Initializing the counter for uppercase letters
    int lowercase = 0; // Initializing the counter for lowercase letters
    
    // Looping through each character in the input word
    for (int i = 0; i < word.length(); i++) {
        char ch = word.at(i); // Getting the character at the current position
        if (isupper(ch)) { // Checking if the character is uppercase
            uppercase++; // Incrementing the uppercase counter
        } else {
            lowercase++; // Incrementing the lowercase counter
        }
    }
    
    // Comparing the counts of uppercase and lowercase letters and printing the result accordingly
    if (uppercase > lowercase) {
        transform(word.begin(), word.end(), word.begin(), ::toupper); // Transforming the word to uppercase if there are more uppercase letters
        cout << word << endl; // Printing the transformed word
    } else if (lowercase > uppercase) {
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Transforming the word to lowercase if there are more lowercase letters
        cout << word << endl; // Printing the transformed word
    } else {
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Transforming the word to lowercase if the counts are equal
        cout << word << endl; // Printing the transformed word
    }
    
    return 0; // Returning 0 to indicate successful execution of the program
}

