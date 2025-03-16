// problem_b.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

const int constMod = 1e9 + 7;

// Function to read an integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read a vector of integers from input
vector<int> getIntSlice(int n) {
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Function to solve the main logic of the program
void solve() {
    int n = getInt();
    int m = getInt();
    vector<int> a = getIntSlice(n);

    int sum = accumulate(a.begin(), a.end(), 0);

    int count = 0;
    for (int v : a) {
        double rate = static_cast<double>(sum) / (4 * m);
        if (static_cast<double>(v) >= rate) {
            count++;
        }
    }

    if (count >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

// Main function
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

// <END-OF-CODE>
