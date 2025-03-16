#include <iostream>
#include <string>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    string word;
    cout << "Enter a word: ";
    cin >> word;
    
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
        cout << word << endl;
    } else if (lowercase > uppercase) {
        // If there are more lowercase letters, print the word in lowercase
        cout << word << endl;
    } else {
        // If the counts are equal, print the word in lowercase
        cout << word << endl;
    }
    
    return 0;
}

