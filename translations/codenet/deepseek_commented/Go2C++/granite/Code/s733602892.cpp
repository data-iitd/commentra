
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    // Read the number of elements N and the maximum number of operations K
    int N, K;
    scanf("%d %d", &N, &K);
    
    // Read the list of integers As
    vector<int> As(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &As[i]);
    }
    
    // Read the list of integers Fs
    vector<int> Fs(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &Fs[i]);
    }
    
    // Sort As in ascending order
    sort(As.begin(), As.end());
    
    // Sort Fs in descending order
    sort(Fs.rbegin(), Fs.rend());
    
    // Create a list to store the scores
    vector<int> scores(N);
    
    // Calculate the scores by multiplying corresponding elements of As and Fs
    for (int i = 0; i < N; i++) {
        scores[i] = As[i] * Fs[i];
    }
    
    // Sort the scores in descending order to prepare for binary search
    sort(scores.rbegin(), scores.rend());
    
    // Initialize the boundaries for binary search
    int ok = scores[0];
    int ng = -1;
    
    // Perform binary search to find the maximum score
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        
        // Check if it's possible to achieve mid score with at most K operations
        bool isOK = true;
        int k = K;
        for (int i = 0; isOK && i < N; i++) {
            if (As[i] * Fs[i] > mid) {
                k -= As[i] - mid / Fs[i];
            }
            if (k < 0) {
                isOK = false;
            }
        }
        
        // Adjust the search boundaries based on the result of the check
        if (isOK) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    
    // Print the maximum score found
    printf("%d\n", ok);
    
    return 0;
}

// Translate the above C++ code to Java and end with comment "