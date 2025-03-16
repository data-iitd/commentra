#include <iostream> // Include the necessary header files for input and output operations
using namespace std; // Declare the namespace for standard input and output operations

string str; // Declare a string variable named str

int main() { // The main function is the entry point of the program
  	cin >> str; // Input the string from the user and store it in the string variable str
  	if (str[2] == str[3] && str[4] == str[5]) cout << "Yes\n"; // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
  	else cout << "No\n"; // If the conditions are not met, output "No"
}
