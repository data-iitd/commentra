#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a single integer from standard input
int I() {
    return (int)std::cin.get();
}

// Function to read a list of integers from standard input
vector<int> LI() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

int main() {
    // Read the number of elements
    int N = I();
    
    // Read the list of integers, sort it in descending order
    vector<int> S = LI();
    sort(S.begin(), S.end(), greater<int>());
    
    // Initialize a flag list to track which elements have been used
    vector<bool> flag(S.size(), true);
    
    // Initialize the current list with the largest element
    vector<int> cur;
    cur.push_back(S[0]);
    
    // Mark the first element as used
    flag[0] = false;
    
    // Iterate N times to build the current list
    for (int i = 0; i < N; i++) {
        int j = 0;  // Index for the current list
        int jM = cur.size();  // Length of the current list
        
        // Try to find the next largest unused element
        for (int k = 0; k < S.size(); k++) {
            // Check if the current element is unused and smaller than the last added element
            if (flag[k] && S[k] < cur[j]) {
                cur.push_back(S[k]);  // Add the element to the current list
                j += 1;  // Move to the next index in the current list
                flag[k] = false;  // Mark this element as used
                
                // If we have added enough elements, break out of the loop
                if (j == jM) {
                    break;
                }
            }
        } else {
            // If we couldn't find a suitable element, return "No"
            return "No";
        }
        
        // Sort the current list in descending order for the next iteration
        sort(cur.begin(), cur.end(), greater<int>());
    }
    
    // If we successfully built the list, return "Yes"
    return "Yes";
}

