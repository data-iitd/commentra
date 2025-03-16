#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

// Function to calculate the absolute value of an integer.
int absint(int a) {
    return (a < 0) ? -a : a;
}

int main(int argc, char* argv[]) {
    ifstream inputFile;
    if (argc > 1) {
        inputFile.open(argv[1]);
        if (!inputFile) {
            cerr << "Unable to open file " << argv[1] << endl;
            return 1;
        }
    } else {
        inputFile.open("/dev/stdin");
    }

    // Read the number of elements.
    int n;
    inputFile >> n;

    // Initialize a vector to store the elements and a sum variable.
    vector<int> aa(n + 2);
    int sum = 0;

    // Read the elements into the vector and calculate the sum of absolute differences.
    for (int i = 0; i < n; i++) {
        inputFile >> aa[i + 1];
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    // Calculate and print the differences for each element.
    for (int i = 1; i <= n; i++) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        cout << ans << endl;
    }

    inputFile.close();
    return 0;
}

// <END-OF-CODE>
