#include<iostream>  // Include the standard input/output library
using namespace std;  // Include the standard namespace
int main()            // Define the main function
{
    char str[30];  // Declare a character array to hold the input string
    cin.getline(str, 30);  // Read input from the user
    str[5] =' ';   // Modify the string by replacing the character at position 5 with a space
    str[13] =' ';  // Modify the string by replacing the character at position 13 with a space
    cout << str << endl;  // Print the modified string to the console
    return 0;     // Return from the main function
}
