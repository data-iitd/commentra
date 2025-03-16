#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Take input from the user
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check if the sum of the elements in the list is divisible by the formula
    if (accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }

    // Calculate the average of the elements in the list
    double k = static_cast<double>(accumulate(a.begin(), a.end(), 0)) / (n * (n + 1) / 2);

    // Add the first element to the end of the list for simplification
    a.push_back(a[0]);

    // Check if the differences between consecutive elements (modulo n) or the ratios of the differences to n are valid
    int sum_mod = 0;
    int sum_ratio = 0;
    for (size_t i = 1; i < a.size(); ++i) {
        sum_mod += static_cast<int>((k - a[i] + a[i - 1]) + n) % n;
        sum_ratio += (k - a[i] + a[i - 1]) / n >= 0 ? 1 : 0;
    }

    if (sum_mod != 0 || sum_ratio != n) {
        cout << "NO" << endl;
        return 0;
    }

    // If all checks pass, print YES
    cout << "YES" << endl;

    return 0;
}

// <END-OF-CODE>
