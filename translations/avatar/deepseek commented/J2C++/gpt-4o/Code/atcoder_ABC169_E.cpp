#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    // Declare and initialize a constant integer
    const int num = 998244353;

    // Read the number of elements 'n' from the input
    int n;
    cin >> n;

    // Create two vectors to store the pairs of integers
    vector<int> ai(n);
    vector<int> bi(n);

    // Read the pairs of integers from the input and store them in the vectors
    for (int i = 0; i < n; i++) {
        cin >> ai[i] >> bi[i];
    }

    // Sort both the vectors
    sort(ai.begin(), ai.end());
    sort(bi.begin(), bi.end());

    // Check if 'n' is odd or even
    if (n % 2 == 1) {
        // If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
        cout << bi[n / 2] - ai[n / 2] + 1 << endl;
    } else {
        // If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
        double b = (ai[n / 2] + ai[n / 2 - 1]) / 2.0;
        double c = (bi[n / 2] + bi[n / 2 - 1]) / 2.0;
        cout << static_cast<int>(2 * (c - b) + 1) << endl;
    }

    return 0;
}

// <END-OF-CODE>
