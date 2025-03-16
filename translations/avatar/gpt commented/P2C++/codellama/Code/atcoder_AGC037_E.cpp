#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read input values for N and K
    int N, K;
    cin >> N >> K;
    // Read the string S
    string S;
    cin >> S;

    // Initialize a flag to determine if we can use a shortcut for output
    bool aaaa = false;

    // Check if K is large enough or if 2^K is greater than or equal to N
    if (K >= 15) {
        aaaa = true;
    } else if (pow(2, K) >= N) {
        aaaa = true;
    }

    // If the shortcut condition is met, print the minimum character repeated N times and exit
    if (aaaa) {
        cout << min(S) * N << endl;
        return 0;
    }

    // Function to get the lexicographically smallest rotation of the string
    string get_last_dict(string s_str) {
        // Create a doubled string to facilitate rotation comparison
        string U = s_str + s_str.substr(s_str.length() - 1, s_str.length() - 1);
        // Find the minimum character in the original string
        char c = min(s_str);
        // Get the first occurrence of the minimum character
        int p = U.find(c);
        int minindex = p;
        p += 1;

        // Iterate through the doubled string to find the smallest rotation
        while (p <= N) {
            if (U[p] == c) {
                // Compare the current rotation with the previously found minimum
                if (check_normal_dict(U, minindex, p)) {
                    minindex = p;
                }
            }
            p += 1;
        }

        // Return the smallest rotation of length N
        return U.substr(minindex, N);
    }

    // Function to compare two rotations of the string
    bool check_normal_dict(string u, int pointer1, int pointer2) {
        // Compare characters of the two rotations
        for (int i = 0; i < N; i++) {
            if (u[pointer1 + i] > u[pointer2 + i]) {
                return true;
            } else if (u[pointer1 + i] < u[pointer2 + i]) {
                return false;
            }
        }
        return false;
    }

    // Get the lexicographically smallest rotation of S
    S = get_last_dict(S);

    // If K is 1, simply print the smallest rotation
    if (K == 1) {
        cout << S << endl;
    } else {
        int count = 0;
        // Count how many times the first character appears consecutively
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == S[0]) {
                count += 1;
            } else {
                break;
            }
        }

        // Check if the repeated character can fill the string of length N
        if (count * (int)pow(2, K - 1) >= N) {
            cout << S[0] * N << endl;
        } else {
            // Construct the output string based on the count and the original string
            S = S[0] * (count * ((int)pow(2, K - 1) - 1)) + S;
            // Print the first N characters of the constructed string
            cout << S.substr(0, N) << endl;
        }
    }

    return 0;
}

