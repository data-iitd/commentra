
#####
# Code
#####

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Define a function to get the last dictionary of the string S
string get_last_dict(string s_str) {
    // Create a new string U by concatenating S with its reverse
    string U = s_str + string(s_str.rbegin(), s_str.rend());
    // Find the minimum character in S
    char c = *min_element(s_str.begin(), s_str.end());
    // Find the index of the first occurrence of the minimum character in U
    int p = U.find(c);
    // Initialize a variable minindex to store the index of the first occurrence of the minimum character in S
    int minindex = p;
    // Move the pointer p to the next character in U
    p += 1;
    // Check if the substring starting from the current pointer and of length N is a normal dictionary
    while (p <= s_str.length()) {
        // If the character at the current pointer in U is the same as the minimum character,
        // and if the substring starting from the current pointer and of length N is a normal dictionary,
        // update the index minindex
        if (U[p] == c && check_normal_dict(U, minindex, p)) {
            minindex = p;
        }
        // Move the pointer p to the next character in U
        p += 1;
    }
    // Return the substring starting from minindex and of length N
    return U.substr(minindex, s_str.length());
}

// Define a function to check if a substring is a normal dictionary
bool check_normal_dict(string u, int pointer1, int pointer2) {
    // Iterate through each character in the substring of length N
    for (int i = 0; i < s_str.length(); i++) {
        // If the character at pointer1+i in U is greater than the character at pointer2+i,
        // return True (indicating that the substring is a normal dictionary)
        if (u[pointer1+i] > u[pointer2+i]) {
            return true;
        }
        // Else, if the character at pointer1+i is less than the character at pointer2+i,
        // return False (indicating that the substring is not a normal dictionary)
        else if (u[pointer1+i] < u[pointer2+i]) {
            return false;
        }
    }
    // If none of the above conditions are met, return False
    return false;
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    // If K is greater than or equal to 15, print the string S repeated N times
    if (K >= 15) {
        cout << string(N, S[0]) << endl;
    }
    // Else, get the last dictionary of the string S
    else {
        S = get_last_dict(S);
        // If K is equal to 1, print the string S
        if (K == 1) {
            cout << S << endl;
        }
        // Else, check if the number of occurrences of the first character in S is greater than or equal to N/2^(K-1)
        else {
            int count = 0;
            for (char c : S) {
                // If the current character is the same as the first character, increment the count
                if (c == S[0]) {
                    count += 1;
                }
                // Else, break the loop
                else {
                    break;
                }
            }
            // If the count is greater than or equal to N/2^(K-1), print the string consisting of the first character repeated N times
            if (count * (1 << (K - 1)) >= N) {
                cout << string(N, S[0]) << endl;
            }
            // Else, construct the string S by concatenating N-1 instances of the first character with the original string S
            else {
                S = string(count * (1 << (K - 1)) - 1, S[0]) + S;
                // Print the first N characters of the constructed string S
                cout << S.substr(0, N) << endl;
            }
        }
    }
    return 0;
}

