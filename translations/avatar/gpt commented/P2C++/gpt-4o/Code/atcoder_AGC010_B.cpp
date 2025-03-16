#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Read the number of elements
    int n;
    cin >> n;

    // Read the list of integers
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check if the sum of the list 'a' is divisible by the sum of the first n natural numbers
    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_n = n * (n + 1) / 2;

    if (sum_a % sum_n != 0) {
        // If not divisible, print "NO" and exit
        cout << "NO" << endl;
    } else {
        // Calculate the average value 'k' that each element should contribute
        double k = static_cast<double>(sum_a) / sum_n;

        // Append the first element of 'a' to the end of the list to facilitate circular calculations
        a.push_back(a[0]);

        // Check if the sum of the adjusted values is zero and if all adjusted values are non-negative
        bool valid = true;
        for (size_t i = 1; i < a.size(); ++i) {
            double adjusted_value = (k - a[i - 1] + a[i]);
            if (static_cast<int>(adjusted_value) % n != 0 || (adjusted_value / n < 0)) {
                valid = false;
                break;
            }
        }

        // If both conditions are satisfied, print "YES"
        if (valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
