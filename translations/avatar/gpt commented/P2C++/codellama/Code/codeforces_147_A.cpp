#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Take input from the user
    string s;
    cin >> s;

    // Initialize an empty vector to store the result
    vector<char> res;

    // Define a list of punctuation marks to check against
    vector<char> punctuation = {',', '.', '!', '?'};

    // Iterate through each character in the input string
    for (int i = 0; i < s.length(); i++)
    {
        // Check if the current index is greater than or equal to 1
        if (i >= 1)
        {
            // If the current character is a space
            if (s[i] == ' ')
            {
                // Only append a space if the last element in res is not a space
                if (res[res.size() - 1] != ' ')
                {
                    res.push_back(s[i]);
                }
                else
                {
                    continue;  // Skip if the last element is already a space
                }
            }
            else
            {
                // If the current character is a punctuation mark
                if (find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end())
                {
                    // If the last element in res is a space, remove it
                    if (res[res.size() - 1] == ' ')
                    {
                        res.pop_back();
                    }
                    // Append the punctuation mark to the result
                    res.push_back(s[i]);
                    // Append a space after the punctuation
                    res.push_back(' ');
                }
                else
                {
                    // If the current character is not punctuation, append it to the result
                    res.push_back(s[i]);
                }
            }
        }
        else
        {
            // For the first character, handle it separately
            if (s[i] == ' ')
            {
                continue;  // Skip if it's a space
            }
            if (find(punctuation.begin(), punctuation.end(), s[i]) != punctuation.end())
            {
                continue;  // Skip if it's a punctuation mark
            }
            else
            {
                // Append the first character to the result if it's not a space or punctuation
                res.push_back(s[i]);
            }
        }
    }

    // Join the vector into a single string and print the result
    string result = "";
    for (int i = 0; i < res.size(); i++)
    {
        result += res[i];
    }
    cout << result << endl;

    return 0;
}

