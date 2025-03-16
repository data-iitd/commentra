
#include <bits/stdc++.h>

using namespace std;

// Initialize a scanner object to read input from the console
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the number of test cases from the console
    int n;
    cin >> n;

    // Define the maximum size of the array to avoid array out of bounds exception
    int N = (int) 1e5 + 5;

    // Initialize an array to store the count of each number
    long long cnt[21];

    // Read the numbers one by one and update the count array accordingly
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num; // Read the next number
        cnt[num + 10]++; // Increment the count of the number
    }

    // Calculate the result using the given formula
    long long res = 0;
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i]; // Calculate the sum of products of pairs of numbers with absolute difference i
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2; // Calculate the sum of squares of numbers equal to 10 and add half of it

    // Print the result to the console
    cout << res;

    return 0;
}

