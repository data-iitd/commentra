
#include <iostream> // Importing the iostream library for input/output
#include <string> // Importing the string library for string manipulation

using namespace std; // Using the standard namespace

int main() {
    string word; // Declaring a string variable to store the input word
    
    // Prompting the user to enter a word
    cout << "Enter a word: ";
    getline(cin, word); // Reading the input word from the user
    
    // Initializing counters for uppercase and lowercase letters
    int uppercase = 0;
    int lowercase = 0;
    
    // Looping through each character in the input word
    for (int i = 0; i < word.length(); i++) {
        char ch = word[i]; // Getting the character at the current index
        
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
        transform(word.begin(), word.end(), word.begin(), ::toupper); // Transforming the word to uppercase
        cout << word << endl;
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Transforming the word to lowercase
        cout << word << endl;
    } else {
        // If the counts are equal, print the word in lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower); // Transforming the word to lowercase
        cout << word << endl;
    }
    
    return 0; // Returning 0 to indicate successful execution
}

