#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to read input from standard input using buffered reader
class Scanner {
public:
    Scanner(istream& is) : is_(is) {}

    string next() {
        string line;
        getline(is_, line);
        return line;
    }

    int nextInt() {
        int value;
        is_ >> value;
        return value;
    }

    long long nextLong() {
        long long value;
        is_ >> value;
        return value;
    }

private:
    istream& is_;
};

// Main function
int main() {
    // Setting up logging
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Creating a new scanner object
    Scanner scanner(cin);

    // Reading input
    int n = scanner.nextInt();
    int x = scanner.nextInt();

    // Initializing arrays
    vector<int> a(n);
    vector<int> v(n);
    copy(a.begin(), a.end(), v.begin());

    // Initializing answer variable
    const long long inf = LLONG_MAX;
    long long ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; ++k) {
        // Initializing variable to store sum of subarray elements
        long long kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; ++i) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = min(v[i], a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = min(v[i], a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = min(ans, kans + static_cast<long long>(k) * x);
    }

    // Printing the answer
    cout << ans << '\n';

    return 0;
}
