#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm> 
using namespace std; 

int main()
{
    // Declare a string variable to store the input
    string s;
    
    // Read input string from the user
    cin >> s;

    // Loop through each character from 'a' to 'z'
    for (char i = 'a'; i <= 'z'; i++)
    {
        // Initialize a counter to track occurrences of the current character
        int a = 0;

        // Loop through each character in the input string
        for (int j = 0; j < s.size(); j++)
        {
            // Check if the current character matches the character being checked
            if (i == s.at(j))
            {
                // Increment the counter if a match is found
                a++;
            }
        }

        // If the character was not found in the input string
        if (a == 0)
        {
            // Output the first missing character and exit the loop
            cout << i << endl;
            break;
        } 

        // If we reach the end of the alphabet and all characters are present
        if (i == 'z')
        {
            // Output "None" if no characters are missing
            cout << "None" << endl;
            break;
        }
    }
}
