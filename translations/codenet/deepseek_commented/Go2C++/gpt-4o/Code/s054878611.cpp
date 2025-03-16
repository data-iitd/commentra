#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// solution function takes an integer n and a vector a as input.
// It initializes a memoization array memo with a size of 1e5 + 2.
// It iterates over the elements of a, incrementing the counts in memo for each element and its neighbors.
// It then iterates over the memo array to find the maximum count, which represents the most frequent element or its neighbors.
// The max function is a helper function to find the maximum of two integers.
int solution(int n, vector<int>& a) {
    vector<int> memo(1e5 + 2, 0);
    for (int num : a) {
        memo[num]++;
        memo[num + 1]++;
        memo[num + 2]++;
    }
    int out = 0;
    for (int num : memo) {
        if (num > 0) {
            out = max(out, num);
        }
    }
    return out;
}

// main function reads the input values, calls the solution function, and prints the result.
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solution(n, a) << endl;
    return 0;
}

// <END-OF-CODE>
