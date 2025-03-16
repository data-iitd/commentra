#include <iostream> // Include the iostream library for input and output
using namespace std; // Use the standard namespace

string str; // Declare a string variable to hold user input

int main() {
    // Read a string input from the user
    cin >> str;

    // Check if the characters at positions 2 and 3 are the same,
    // and if the characters at positions 4 and 5 are the same
    if (str[2] == str[3] && str[4] == str[5]) 
        cout << "Yes\n"; // If both conditions are true, output "Yes"
    else 
        cout << "No\n"; // If either condition is false, output "No"
}
