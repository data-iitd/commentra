
#include <iostream> // Importing the necessary classes from the std namespace
#include <vector> // Importing the necessary classes from the std namespace

using namespace std;

int main() {
    // Reading an integer n from user input, which represents the number of elements
    int n;
    cin >> n;
    
    // Initializing a vector to store the indices of elements that are equal to 1
    vector<int> arr;

    // Looping through the input values to find indices of elements equal to 1
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            arr.push_back(i);
        }
    }

    // Checking if the vector of indices is empty
    if (arr.empty()) {
        // If the vector is empty, print 0
        cout << 0 << endl;
    } else {
        // If the vector is not empty, initialize a result variable to 1
        long long result = 1;

        // Calculate the product of the differences between consecutive indices
        for (int i = 1; i < arr.size(); i++) {
            result *= arr.at(i) - arr.at(i - 1);
        }

        // Print the final result
        cout << result << endl;
    }

    return 0;
}
