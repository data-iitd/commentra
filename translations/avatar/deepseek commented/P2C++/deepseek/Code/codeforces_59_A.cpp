#include <iostream>
#include <string>
using namespace std;

int main() {
    string txt;
    int cu = 0, cl = 0;

    // Taking input from the user and storing it in the variable `txt`.
    getline(cin, txt);

    // Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
    for (char z : txt) {
        if (islower(z)) {  // Checking if the current character `z` is lowercase.
            cl = cl + 1;  // Incrementing the counter for lowercase letters if `z` is lowercase.
        } else {  // If `z` is not lowercase, it must be uppercase.
            cu = cu + 1;  // Incrementing the counter for uppercase letters.
        }
    }

    // Comparing the counts of uppercase and lowercase letters to decide the case of the output.
    if (cu > cl) {  // If there are more uppercase letters than lowercase letters.
        for (char &z : txt) {  // Convert the entire text to uppercase.
            z = toupper(z);
        }
    } else {  // If there are more lowercase letters than uppercase letters or equal counts.
        for (char &z : txt) {  // Convert the entire text to lowercase.
            z = tolower(z);
        }
    }

    // Printing the result stored in `txt`.
    cout << txt << endl;

    return 0;
}
