#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Arrays to store input values
int a[100000];
int b[100000];
int c[100000];
int d[100000];

// Variables to store input values
int n = 0;
int m = 0;
int q = 0;

// Variable to store the maximum score
long ans = -100L;

// Function to calculate the score
long calculateScore(vector<int> list) {
    long score = 0L;
    for (int i = 0; i < q; ++i) {
        if (list[b[i]] - list[a[i]] == c[i]) {
            score += d[i];
        }
    }
    return score;
}

// Function to generate combinations
void dfs(vector<int> list) {
    // If the list size equals n, calculate the score and update ans
    if (list.size() == n) {
        long score = calculateScore(list);
        ans = max(ans, score);
        return;
    }
    
    // If the list is not empty, continue adding numbers from the last number in the list
    if (!list.empty()) {
        for (int num = list.back(); num <= m; ++num) {
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    } else {
        // If the list is empty, start with numbers from 1 to m
        for (int num = 1; num <= m; ++num) {
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    }
}

int main() {
    // Read values of n, m, and q
    cin >> n >> m >> q;
    
    // Initialize arrays to store the conditions
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; // Adjusting for 0-based index
        --b[i]; // Adjusting for 0-based index
    }
    
    // Start the DFS with an empty list
    vector<int> list;
    dfs(list);
    
    // Print the maximum score found
    cout << ans << endl;
    
    return 0;
}

