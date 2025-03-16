#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to resolve the problem
void resolve( ) {

    // Read the number of test cases
    int n;
    cin >> n;

    // Initialize empty vectors to store low and high values
    vector<int> low;
    vector<int> high;

    // Read low and high values for each test case and append to respective vectors
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        low.push_back(a);
        high.push_back(b);
    }

    // Sort the low and high vectors in ascending order
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());

    // Check if the number of test cases is odd
    if (n % 2) {
        // If it is odd, print the difference between the middle low and middle high values
        cout << high[(n+1)/2-1] - low[(n+1)/2-1] + 1 << endl;
    } else {
        // If it is even, calculate the average of middle low and middle high values
        int hh = (high[(n)/2-1] + high[(n)/2]) / 2;
        int ll = (low[(n)/2-1] + low[(n)/2]) / 2;

        // Print the result which is twice the difference between the averages
        cout << int((hh-ll)*2)+1 << endl;
    }
}

