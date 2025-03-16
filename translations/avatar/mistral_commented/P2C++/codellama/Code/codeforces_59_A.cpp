#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Get the text input from the user
    string txt;
    cin >> txt;

    // Initialize the count of uppercase and lowercase characters
    int cu = 0, cl = 0;

    // Iterate through each character in the text input
    for (int i = 0; i < txt.length(); i++)
    {
        // If the character is lowercase, increment the lowercase count
        if (txt[i] >= 'a' && txt[i] <= 'z')
            cl++;
        // If the character is uppercase, increment the uppercase count
        else
            cu++;
    }

    // Determine the output based on the count of uppercase and lowercase characters
    string out;
    if (cu > cl)
        // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
        out = txt.uppercase();
    else
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        out = txt.lowercase();

    // Print the output
    cout << out << endl;

    return 0;
}

