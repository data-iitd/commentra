#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Initialize input and output streams
    istream& fp = cin;
    ostream& wfp = cout;

    // If input file and output file are provided as command line arguments
    if (argc > 1) {
        // Open the input file
        fp.open(argv[1]);

        // If output file is provided, create it
        if (argc > 2) {
            wfp.open(argv[2]);
        }
    }

    // Read the number of elements in the array
    int n;
    fp >> n;

    // Initialize a vector of size n to store the elements
    vector<int> ll(n);

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        fp >> ll[i];
    }

    // Sort the vector in ascending order
    sort(ll.begin(), ll.end());

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through all possible pairs of elements
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // Initialize the left and right pointers for binary search
            int l = j + 1;
            int r = n;

            // Binary search to find the index of the element greater than the sum of the current pair
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }

            // Update the answer variable
            ans += l - (j + 1);
        }
    }

    // Write the answer to the output file
    wfp << ans << endl;

    return 0;
}
