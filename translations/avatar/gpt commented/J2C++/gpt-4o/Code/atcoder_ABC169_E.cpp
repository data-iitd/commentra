#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    // Define a constant number for modulo operations
    const int num = 998244353;

    // Read the number of pairs (n) from input
    int n;
    cin >> n;

    // Create two vectors to store the two sets of integers
    vector<int> ai, bi;

    // Read n pairs of integers from input
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ai.push_back(a);
        bi.push_back(b);
    }

    // Sort both vectors to prepare for median calculation
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());

    // Check if the number of elements is odd
    if (n % 2 == 1) {
        // Calculate the result for odd n using the median values
        cout << bi[n / 2] - ai[n / 2] + 1 << endl;
    } else {
        // Calculate the average of the two middle values for even n
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        // Calculate the result for even n and print it
        cout << static_cast<int>(2 * (c - b) + 1) << endl;
    }

    return 0;
}

// <END-OF-CODE>
