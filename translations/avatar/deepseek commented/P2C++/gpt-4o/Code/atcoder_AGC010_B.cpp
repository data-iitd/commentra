#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read the list elements
    }

    if (accumulate(a.begin(), a.end(), 0) % (n * (n + 1) / 2) != 0) {
        // Check if the sum of the list is divisible by the triangular number (n * (n + 1) / 2)
        cout << "NO" << endl;
    } else {
        double k = static_cast<double>(accumulate(a.begin(), a.end(), 0)) / (n * (n + 1) / 2);
        // Calculate the quotient k by dividing the sum of the list by the triangular number
        a.push_back(a[0]); // Append the first element to the end of the list to create a circular list

        bool condition1 = false;
        bool condition2 = true;
        for (size_t i = 1; i < a.size(); ++i) {
            double temp = (k - a[i] + a[i - 1]) / n;
            if (temp < 0) {
                condition1 = true; // Check if any value is negative
            }
            if (temp >= 0) {
                condition2 = condition2 && (temp >= 0);
            }
        }

        if (condition1 || (condition2 && (a.size() - 1) != n)) {
            // Check if the condition is met for all elements in the circular list
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            // If the condition is met, print "YES"
        }
    }

    return 0;
}
