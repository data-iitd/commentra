#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void editorial(int N, vector<int>& P) {
    // If there is only one element, print 0 and return
    if (N == 1) {
        cout << 0 << endl;
        return;
    }
    
    // Initialize an array to store positions of elements in P
    vector<int> a(N + 1, 0);
    
    // Populate the array with positions of elements in P
    for (int i = 0; i < N; ++i) {
        a[P[i]] = i;
    }
    
    // Initialize temporary and maximum length variables
    int tmp = 1;
    int max_len = 1;
    
    // Iterate through the positions to find the maximum length of consecutive increasing elements
    for (int i = 1; i < N; ++i) {
        if (a[i] < a[i + 1]) {
            tmp += 1;
            max_len = max(max_len, tmp);
        } else {
            tmp = 1;
        }
    }
    
    // Calculate the answer as N - max_len
    int ans = N - max_len;
    
    // Print the answer
    cout << ans << endl;
}

void WA(int N, vector<int>& P) {
    int tmp = 0;
    int ans = 0;
    
    for (int i = 0; i < N; ++i) {
        if (i == 0 || P[i - 1] + 1 == P[i]) {
            tmp += 1;
        } else {
            ans = max(ans, tmp);
            tmp = 1;
        }
    }
    
    cout << N - ans << endl;
}

int main() {
    // Read the number of elements N
    int N;
    cin >> N;
    
    // Read the list of integers P
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    
    // Call the editorial function with N and P as arguments
    editorial(N, P);
    
    return 0;
}

// <END-OF-CODE>
