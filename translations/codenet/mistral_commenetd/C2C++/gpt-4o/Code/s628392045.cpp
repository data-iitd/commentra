// Include necessary header files
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Declare and initialize variables
int n;
vector<int> h;
int max_height = -1;
bool flag = false;

int main() {
    // Read the number of test cases
    cin >> n;
    h.resize(n);

    // Read and process input
    for(int i = 0; i < n; i++) {
        // Read the next integer from standard input and store it in the vector h
        cin >> h[i];

        // Update the maximum height if the current height is greater
        if(max_height < h[i]) max_height = h[i];

        // Check if the difference between the current height and maximum height is greater than or equal to 2
        if(max_height - h[i] >= 2) flag = true;
    }

    // Check the value of the flag and print the appropriate message to the standard output
    if(flag) cout << "No" << endl;
    else cout << "Yes" << endl;

    // Return 0 to indicate successful execution
    return 0;
}

// <END-OF-CODE>
