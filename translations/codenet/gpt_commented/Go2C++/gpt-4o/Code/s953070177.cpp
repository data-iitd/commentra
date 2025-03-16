#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

// Function to calculate the absolute value of an integer.
int absint(int a) {
    return (a < 0) ? -a : a;
}

int main(int argc, char* argv[]) {
    // Determine the input source: standard input or a file specified as a command-line argument.
    ifstream inputFile;
    if (argc > 1) {
        inputFile.open(argv[1]);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return 1;
        }
    }
    istream& input = (argc > 1) ? inputFile : cin;

    // Read the number of elements from the input.
    int n;
    input >> n;

    // Initialize a vector to hold the elements and a variable to store the total sum of absolute differences.
    vector<int> aa(n + 2);
    int sum = 0;

    // Read the elements into the vector and calculate the total sum of absolute differences between consecutive elements.
    for (int i = 0; i < n; i++) {
        input >> aa[i + 1];
        sum += absint(aa[i + 1] - aa[i]);
    }
    // Include the difference between the last element and the element before it.
    sum += absint(aa[n + 1] - aa[n]);

    // Calculate and print the result for each element.
    for (int i = 1; i <= n; i++) {
        // Calculate the new sum of absolute differences if the i-th element is removed.
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        cout << ans << endl; // Output the result for the current element.
    }

    // Close the input file if it was opened.
    if (inputFile.is_open()) {
        inputFile.close();
    }

    return 0;
}

// <END-OF-CODE>
