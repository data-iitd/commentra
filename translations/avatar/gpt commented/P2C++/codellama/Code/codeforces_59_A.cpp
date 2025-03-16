#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Get input from the user
    string txt;
    cin >> txt;

    // Initialize counters for uppercase and lowercase letters
    int cu = 0;  // Counter for uppercase letters
    int cl = 0;  // Counter for lowercase letters

    // Iterate through each character in the input text
    for (int i = 0; i < txt.length(); i++)
    {
        // Check if the character is lowercase
        if (txt[i] >= 'a' && txt[i] <= 'z')
        {
            cl++;  // Increment lowercase counter
        }
        else
        {
            cu++;  // Increment uppercase counter
        }
    }

    // Compare the counts of uppercase and lowercase letters
    if (cu > cl)
    {
        // If there are more uppercase letters, convert the text to uppercase
        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                txt[i] = txt[i] - 32;
            }
        }
    }
    else
    {
        // If there are more lowercase letters or they are equal, convert the text to lowercase
        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                txt[i] = txt[i] + 32;
            }
        }
    }

    // Print the resulting output
    cout << txt << endl;

    return 0;
}

