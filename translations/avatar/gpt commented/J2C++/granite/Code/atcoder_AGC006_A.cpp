
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a constant for the maximum size of the arrays
const int N = 200 + 10;
// Array to store the failure function values
int f[N];
// Array to store the concatenated strings
char b[N];

// Function to compute the failure function for the KMP algorithm
void getFail(char b[], int m) {
    int j = 0; // Initialize j to track the length of the previous longest prefix suffix
    f[0] = f[1] = 0; // Base cases for the failure function

    // Loop through the string to fill the failure function
    for (int i = 2; i <= m; i++) {
        // Adjust j until we find a match or j becomes 0
        while (j > 0 && b[j + 1]!= b[i])
            j = f[j];
        // If there is a match, increment j
        if (b[j + 1] == b[i])
            j++;
        // Set the failure function value for the current position
        f[i] = j;
    }
}

int main() {
    // Create an input reader and output writer
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Read the length of the strings
    int n;
    cin >> n;
    // Read the two strings
    string s1, str;
    cin >> s1 >> str;
    int cnt = 0;

    // Concatenate the second string into the character array
    for (int i = 0; i < n; i++)
        b[++cnt] = str[i];
    // Concatenate the first string into the character array
    for (int i = 0; i < n; i++)
        b[++cnt] = s1[i];

    // Compute the failure function for the concatenated strings
    getFail(b, cnt);

    // Calculate the length of the longest prefix which is also a suffix
    int len = min(f[cnt], min(n, n));
    // Output the result based on the calculated length
    cout << 2 * n - len << endl;

    return 0;
}

// Translate the above C++ code to Python and end with comment "