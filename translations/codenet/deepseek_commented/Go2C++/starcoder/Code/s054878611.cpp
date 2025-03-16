#include <iostream>
#include <vector>

using namespace std;

// solution function takes an integer n and a vector<int> a as input.
// It initializes a vector<int> memo with a size of 1e5 + 2.
// It iterates over the elements of a, incrementing the counts in memo for each element and its neighbors.
// It then iterates over the memo array to find the maximum count, which represents the most frequent element or its neighbors.
// The max function is a helper function to find the maximum of two integers.
// The main function reads the input values, calls the solution function, and prints the result.
int solution(int n, vector<int> a) {
        vector<int> memo(1e5 + 2, 0);
        for (int i = 0; i < n; i++) {
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        int out = 0;
        for (int i = 0; i < memo.size(); i++) {
                if (memo[i] > 0) {
                        out = max(out, memo[i]);
                }
        }
        return out;
}

// max function returns the maximum of two integers.
int max(int x, int y) {
        if (x > y) {
                return x;
        }
        return y;
}

// main function reads the input values, calls the solution function, and prints the result.
int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        cout << solution(n, a);
        return 0;
}

