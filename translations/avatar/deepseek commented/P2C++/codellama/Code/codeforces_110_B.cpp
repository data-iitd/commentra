
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string LUCKY = "abcd";
    // Define a string LUCKY containing the characters "abcd"

    int n;
    // Take an integer input n from the user
    cin >> n;

    string s = "";
    // Initialize an empty string s to store the result

    for (int i = 0; i < n; i++)
    {
        // Loop n times to construct the string s
        s += LUCKY[i % 4];
        // Append a character from LUCKY to s based on the index i modulo 4
    }

    cout << s << endl;
    // Print the final string s

    return 0;
}

