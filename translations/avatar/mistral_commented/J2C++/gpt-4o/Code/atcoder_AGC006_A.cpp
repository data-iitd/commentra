#include <iostream>  // Importing required C++ headers for input and output
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int N = 200 + 10;  // Initializing the size of the arrays
int f[N];  // Initializing the failure function array
char b[N];  // Initializing the character arrays

void getFail(char b[], int m) {
    // Function declaration and initialization of variables
    int j = 0;
    f[0] = f[1] = 0;  // Initializing the first two elements of the failure function array

    // Main logic of the function
    for (int i = 2; i <= m; i++) {
        while (j > 0 && b[j + 1] != b[i]) j = f[j];  // Searching for the longest common prefix of the current and previous strings
        if (b[j + 1] == b[i]) j++;  // If the characters match, move to the next character in the current string
        f[i] = j;  // Updating the failure function for the current index
    }
}

int main() {
    // Main function declaration and initialization of variables
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;  // Number of characters in the strings
    cin >> n;  // Reading the number of characters
    string s1, str;  // Strings to hold the input
    cin >> str >> s1;  // Reading the two strings

    int cnt = 0;  // Initializing a counter for the number of characters in the combined string

    // Concatenating the two strings and creating character arrays for each
    for (int i = 0; i < n; i++) b[++cnt] = str[i];
    for (int i = 0; i < n; i++) b[++cnt] = s1[i];

    getFail(b, cnt);  // Calling the getFail function to compute the failure function

    int len = min(f[cnt], min(n, n));  // Computing the length of the longest common prefix

    cout << 2 * n - len << '\n';  // Writing the output to the console

    return 0;  // End of the program
}

// <END-OF-CODE>
