
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Initializing standard input and output file pointers
    FILE *fp = freopen("input.txt", "r", stdin);
    FILE *wfp = freopen("output.txt", "w", stdout);

    // If input file and output file are provided as command line arguments
    if (argc > 1) {
        // Open the input file
        fp = freopen(argv[1], "r", stdin);

        // If output file is provided, create it
        if (argc > 2) {
            wfp = freopen(argv[2], "w", stdout);
        }
    }

    // Initialize a new scanner for reading input
    scanf("%d", &n);

    // Initialize a slice of length n to store the elements
    int ll[n];

    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &ll[i]);
    }

    // Sort the slice in ascending order
    sort(ll, ll + n);

    // Initialize the answer variable to 0
    int ans = 0;

    // Iterate through all possible pairs of elements
    for (int i = 0; i < n - 2; i++) {
        // Iterate through all possible right pointers
        for (int j = i + 1; j < n - 1; j++) {
            // Initialize the left and right pointers for binary search
            int l = j + 1;
            int r = n;

            // Binary search to find the index of the element greater than the sum of the current pair
            while (l < r) {
                int m = (l + r) >> 1;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                    continue;
                }
                r = m;
            }

            // Update the answer variable
            ans += l - (j + 1);
        }
    }

    // Write the answer to the output file
    printf("%d\n", ans);

    // Flush the writer buffer
    fflush(wfp);

    // Close the input and output files
    fclose(fp);
    fclose(wfp);

    return 0;
}

