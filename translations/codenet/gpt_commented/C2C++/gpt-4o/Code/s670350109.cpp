#include <iostream>
#include <cstring>

using namespace std;

// Declare character arrays to hold two strings and a temporary string for manipulation
char str1[100], str2[100], temp[100];

int main()
{
    int i, j = 0, t;

    // Read two strings from user input
    cin.getline(str1, 100);
    cin.getline(str2, 100);

    // Get the length of the first string and calculate the last index
    i = strlen(str1);
    t = i - 1;

    // Check if the lengths of the two strings are different
    if(strlen(str1) != strlen(str2))
    {
        // If lengths are different, they cannot be anagrams
        cout << "NO" << endl;
    }
    else
    {
        // Reverse the first string and store it in the temporary array
        while(str1[j] != '\0')
        {
            temp[j] = str1[t]; // Copy characters from the end of str1 to temp
            j++;
            t--;
        }
        // Null-terminate the reversed string
        temp[j] = '\0'; // Ensure the reversed string is properly terminated

        // Reset counters for comparison
        t = 0;
        i = 0;

        // Compare the reversed string with the second string
        while(temp[i] != '\0')
        {
            if(temp[i] == str2[i])
            {
                t++; // Count matching characters
            }
            i++;
        }

        // Check if all characters matched
        if(strlen(str2) == t)
        {
            // If all characters match, the strings are anagrams
            cout << "YES" << endl;
        }
        else if(strlen(str2) != t)
        {
            // If not all characters match, they are not anagrams
            cout << "NO" << endl;
        }
    }
    return 0; // End of the program
}

// <END-OF-CODE>
