#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
    // Take input string from the user
    string S;
    cin >> S;

    // Create a map to count the frequency of each character in the string
    map<char, int> c;

    // Iterate over each character in the input string
    for (int i = 0; i < S.length(); i++)
    {
        // Increment the count of the current character
        c[S[i]]++;
    }

    // Create a set of unique characters from the input string
    set<char> Sa;

    // Iterate over each character in the input string
    for (int i = 0; i < S.length(); i++)
    {
        // Insert the current character into the set
        Sa.insert(S[i]);
    }

    // Check if the number of unique characters is not equal to 2
    if (Sa.size() != 2)
    {
        // If there are not exactly 2 unique characters, print "No" and exit
        cout << "No" << endl;
        return 0;
    }

    // Iterate over each unique character in the set
    for (auto i : Sa)
    {
        // Check if the count of the current character is not equal to 2
        if (c[i] != 2)
        {
            // If any character does not appear exactly twice, print "No" and exit
            cout << "No" << endl;
            return 0;
        }
    }

    // If both conditions are satisfied, print "Yes"
    cout << "Yes" << endl;

    // End of code
    return 0;
}

