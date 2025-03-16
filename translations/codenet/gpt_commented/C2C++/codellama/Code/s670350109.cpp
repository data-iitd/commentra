#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2, temp;

    // Read two strings from user input
    cin >> str1;
    cin >> str2;

    // Get the length of the first string and calculate the last index
    int i = str1.length();
    int t = i - 1;

    // Check if the lengths of the two strings are different
    if(str1.length() != str2.length())
    {
        // If lengths are different, they cannot be anagrams
        cout << "NO\n";
    }
    else
    {
        // Reverse the first string and store it in the temporary array
        while(str1[i] != '\0')
        {
            temp[i] = str1[t]; // Copy characters from the end of str1 to temp
            i++;
            t--;
        }
        // Null-terminate the reversed string
        temp[i] = '\0'; // Ensure the reversed string is properly terminated

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
        if(str2.length() == t)
        {
            // If all characters match, the strings are anagrams
            cout << "YES\n";
        }
        else if(str2.length() != t)
        {
            // If not all characters match, they are not anagrams
            cout << "NO\n";
        }
    }
    return 0; // End of the program
}

