#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a substring is a normal dictionary
bool check_normal_dict(const string& u, int pointer1, int pointer2, int N) {
    for (int i = 0; i < N; i++) {
        if (u[pointer1 + i] > u[pointer2 + i]) {
            return true; // substring is a normal dictionary
        } else if (u[pointer1 + i] < u[pointer2 + i]) {
            return false; // substring is not a normal dictionary
        }
    }
    return false; // none of the conditions met
}

// Function to get the last dictionary of the string S
string get_last_dict(const string& s_str, int N) {
    string U = s_str + string(s_str.rbegin(), s_str.rend()); // Concatenate S with its reverse
    char c = *min_element(s_str.begin(), s_str.end()); // Find the minimum character in S
    int p = U.find(c); // Find the index of the first occurrence of the minimum character in U
    int minindex = p; // Initialize minindex
    p++; // Move the pointer to the next character

    // Check for normal dictionary
    while (p <= N) {
        if (U[p] == c && check_normal_dict(U, minindex, p, N)) {
            minindex = p; // Update minindex
        }
        p++; // Move to the next character
    }
    return U.substr(minindex, N); // Return the substring starting from minindex of length N
}

int main() {
    // Define input variables
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Initialize a flag variable
    bool aaaa = false;

    // Check if K is greater than or equal to 15
    if (K >= 15) {
        aaaa = true; // Set the flag variable to True
    } 
    // Else, check if 2^K is greater than or equal to N
    else if ((1 << K) >= N) { // 2^K is equivalent to (1 << K)
        aaaa = true; // Set the flag variable to True
    }

    // If the flag variable is True, print the result and exit the function
    if (aaaa) {
        cout << string(N, *min_element(S.begin(), S.end())) << endl; // Print min(S) * N
        return 0; // Exit the function
    }

    // Get the last dictionary of the string S
    S = get_last_dict(S, N);

    // If K is equal to 1, print the string S
    if (K == 1) {
        cout << S << endl;
    } else {
        int count = 0;
        for (char c : S) {
            if (c == S[0]) {
                count++; // Increment the count
            } else {
                break; // Break the loop
            }
        }
        // If the count is greater than or equal to N / 2^(K-1)
        if (count * (1 << (K - 1)) >= N) { // 2^(K-1) is equivalent to (1 << (K - 1))
            cout << string(N, S[0]) << endl; // Print S[0] * N
        } else {
            S = string(count * (1 << (K - 1)) - 1, S[0]) + S; // Construct the string
            cout << S.substr(0, N) << endl; // Print the first N characters of the constructed string S
        }
    }

    return 0;
}

// <END-OF-CODE>
