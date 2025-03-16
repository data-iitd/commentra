#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a vector A
    vector<int> A;
    string line;
    getline(cin, line);
    stringstream ss(line);
    int temp;
    while (ss >> temp) {
        A.push_back(temp);
    }

    // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print 0
        cout << 0 << endl;
    } else {
        // If the condition is false, sort the vector A in ascending order
        sort(A.begin(), A.end());
        // Calculate the difference between the largest and the second largest elements in the sorted vector and print the result
        cout << A[2] - A[1] << endl;
    }

    return 0;
}

