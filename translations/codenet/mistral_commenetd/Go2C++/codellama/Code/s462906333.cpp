// Importing necessary packages
#include <bits/stdc++.h>

// Constants and variables declaration
const int inf = 1e14;

// Function to read input from standard input using buffered scanner
class scanner {
    private:
        std::string buffer;
        std::string::iterator it;

    public:
        scanner() {
            buffer = "";
            it = buffer.begin();
        }

        void readLine() {
            std::getline(std::cin, buffer);
            it = buffer.begin();
        }

        int next() {
            while (it != buffer.end() && *it < '0') {
                it++;
            }
            int result = 0;
            while (it != buffer.end() && *it >= '0') {
                result = result * 10 + *it - '0';
                it++;
            }
            return result;
        }

        int Int() {
            return next();
        }

        int Int64() {
            return next();
        }

        std::string Line() {
            while (it != buffer.end() && *it < '0') {
                it++;
            }
            std::string result = "";
            while (it != buffer.end() && *it >= '0') {
                result += *it;
                it++;
            }
            return result;
        }
};

// Main function
int main() {
    // Setting up logging
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Creating a new scanner object
    scanner next;

    // Reading input
    int n = next.Int();
    int x = next.Int();

    // Initializing arrays
    std::vector<int> a(n);
    std::vector<int> v(n);
    v = a;

    // Initializing answer variable
    int ans = inf;

    // Iterating through all possible subarrays
    for (int k = 0; k < n; k++) {
        // Initializing variable to store sum of subarray elements
        int kans = 0;

        // Iterating through all elements of the subarray
        for (int i = 0; i < n; i++) {
            // Checking if current index is out of bounds for subarray
            if (i - k < 0) {
                // Updating current element in subarray with minimum of itself and corresponding element from the main array
                v[i] = std::min(v[i], a[n + i - k]);
            } else {
                // Updating current element in subarray with minimum of itself and previous element in subarray
                v[i] = std::min(v[i], a[i - k]);
            }

            // Adding current element to the sum of subarray
            kans += v[i];
        }

        // Updating answer with minimum of current answer and sum of subarray and multiplication of its size and x
        ans = std::min(ans, kans + k * x);
    }

    // Printing the answer
    std::cout << ans << std::endl;

    return 0;
}

