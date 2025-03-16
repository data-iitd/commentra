
#include <bits/stdc++.h>

using namespace std;

// Function to read an integer from standard input
int I() {
    return scanf("%d", &x);
}

// Function to read a list of integers from standard input
vector<int> LI() {
    vector<int> x;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        x.push_back(t);
    }
    return x;
}

int main() {
    // Read the number of elements N
    int N;
    I();
    
    // Read the list of integers S, sort them in descending order
    vector<int> S = LI();
    sort(S.begin(), S.end(), greater<int>());
    
    // Initialize a flag array to keep track of used elements
    vector<bool> flag(S.size(), true);
    
    // Initialize the current list with the first element of S
    vector<int> cur;
    cur.push_back(S[0]);
    
    // Set the flag for the first element to False
    flag[0] = false;
    
    // Loop through N times
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur.size();
        
        // Iterate over the elements of S
        for (int k = 0; k < S.size(); k++) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to False, and increment j
                cur.push_back(S[k]);
                j += 1;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j == jM) {
            return "No";
        }
        
        // Sort cur in descending order
        sort(cur.begin(), cur.end(), greater<int>());
    }
    
    // Return "Yes" if the condition is satisfied
    return "Yes";
}

