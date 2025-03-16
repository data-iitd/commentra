#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // Set up input stream to read integers
    stringstream ss;
    string input;
    getline(cin, input);
    ss.str(input);
    int n, k;
    ss >> n >> k;

    // Read 'n' integers into vector 'a'
    vector<int> a(n);
    getline(cin, input);
    ss.clear();
    ss.str(input);
    for (int i = 0; i < n; i++) {
        ss >> a[i];
    }

    // Initialize sum with the value of k and set ans to 1
    int sum = k;
    int ans = 1;

    // Loop to calculate how many times we can add k to the sum until it reaches or exceeds n
    while (sum < n) {
        sum = sum - 1 + k; // Update sum by subtracting 1 and adding k
        ans++; // Increment the answer counter
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}
