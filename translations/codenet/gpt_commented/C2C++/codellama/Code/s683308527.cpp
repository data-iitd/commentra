#include<iostream>
#include<cstring>

using namespace std;

int main() {
    int n; // Variable to store the number of lines to read
    char s[10010]; // Array to store each line of input
    char *c; // Pointer to search for the substring "Hoshino"

    // Read the number of lines to process, ignoring the newline character
    cin >> n;

    // Loop to process each line of input
    while(n--) {
        // Read a line of input from stdin
        cin.getline(s, 1010);

        // Search for the substring "Hoshino" in the input line
        // Replace the character following "Hoshino" with 'a'
        while(c = strstr(s, "Hoshino")) {
            *(c + 6) = 'a'; // Replace the character after "Hoshino" with 'a'
        }

        // Print the modified line
        cout << s << endl;
    }

    return 0; // Return 0 to indicate successful completion
}

