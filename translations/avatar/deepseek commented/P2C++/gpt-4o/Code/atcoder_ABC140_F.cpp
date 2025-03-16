#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read an integer from standard input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from standard input
vector<int> LI(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    return vec;
}

string mainLogic() {
    // Read the number of elements N
    int N = I();
    
    // Read the list of integers S, sort them in descending order
    vector<int> S = LI(N);
    sort(S.begin(), S.end(), greater<int>());
    
    // Initialize a flag array to keep track of used elements
    vector<bool> flag(S.size(), true);
    
    // Initialize the current list with the first element of S
    vector<int> cur;
    cur.push_back(S[0]);
    
    // Set the flag for the first element to false
    flag[0] = false;
    
    // Loop through N times
    for (int i = 0; i < N; ++i) {
        int j = 0;
        int jM = cur.size();
        
        // Iterate over the elements of S
        for (int k = 0; k < S.size(); ++k) {
            if (flag[k] && S[k] < cur[j]) {
                // Add the element to cur, set its flag to false, and increment j
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        
        // If no such element is found, return "No"
        if (j < jM) {
            return "No";
        }
        
        // Sort cur in descending order
        sort(cur.begin(), cur.end(), greater<int>());
    }
    
    // Return "Yes" if the condition is satisfied
    return "Yes";
}

int main() {
    // Print the result of the main logic function
    cout << mainLogic() << endl;
    return 0;
}

// <END-OF-CODE>
