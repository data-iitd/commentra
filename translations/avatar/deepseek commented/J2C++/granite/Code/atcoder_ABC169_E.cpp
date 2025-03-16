

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declare and initialize a constant integer
    int num = 998244353;

    // Create a BufferedReader object to read input from the standard input
    BufferedReader bf(new InputStreamReader(cin));

    // Create a PrintWriter object to write output to the standard output
    PrintWriter out(cout);

    // Read the number of elements 'n' from the input
    int n;
    cin >> n;

    // Create two vectors to store the pairs of integers
    vector<int> a, b;

    // Read the pairs of integers from the input and store them in the vectors
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int x, y;
        ss >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    // Sort both the vectors
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Check if 'n' is odd or even
    if (n % 2 == 1) {
        // If 'n' is odd, calculate the range by subtracting the middle element of 'b' from the middle element of 'a' and add 1
        out << b[n / 2] - a[n / 2] + 1 << endl;
    } else {
        // If 'n' is even, calculate the range by averaging the middle elements of 'a' and 'b' and multiply by 2, then add 1
        double b_mid = (a[n / 2] + a[n / 2 - 1]) / 2.0;
        double c_mid = (b[n / 2] + b[n / 2 - 1]) / 2.0;
        out << (int)(2 * (c_mid - b_mid) + 1) << endl;
    }

    return 0;
}
