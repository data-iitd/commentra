#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

// Function to calculate the absolute value of an integer
int absint(int a) {
    return (a < 0) ? -a : a;
}

// Main function
int main(int argc, char* argv[]) {
    // Open the standard input or a file if an argument is provided
    ifstream inputFile;
    if (argc > 1) {
        inputFile.open(argv[1]);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return 1;
        }
    } else {
        inputFile.open("/dev/stdin");
    }

    // Read the first integer from the input
    int n;
    inputFile >> n;

    // Initialize a vector 'aa' of size 'n+2'
    vector<int> aa(n + 2);
    // Initialize a variable 'sum' to store the sum of absolute differences between consecutive elements
    int sum = 0;

    // Iterate through the vector 'aa' and calculate the sum of absolute differences between consecutive elements
    for (int i = 0; i < n; i++) {
        inputFile >> aa[i + 1];
        sum += absint(aa[i + 1] - aa[i]);
    }
    // Calculate the absolute difference between the last two elements and add it to the sum
    sum += absint(aa[n + 1] - aa[n]);

    // Iterate through the vector 'aa' and print the answer for each subarray
    for (int i = 1; i < n + 1; i++) {
        // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        cout << ans << endl;
    }

    // Close the input file if it was opened
    if (inputFile.is_open()) {
        inputFile.close();
    }

    return 0;
}

// <END-OF-CODE>
