#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Prompt the user for input and read the input string
    string user_input;
    cout << "Enter a string: ";
    getline(cin, user_input);

    // Replace all commas in the input string with spaces
    string modified_input = user_input.replace(",", " ");

    // Print the modified input string
    cout << modified_input << endl;

    return 0;
}
