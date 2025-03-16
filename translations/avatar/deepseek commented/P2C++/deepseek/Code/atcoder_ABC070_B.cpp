#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A;
    int num;
    string input;

    // Taking input from the user and converting it into a vector of integers
    getline(cin, input);
    stringstream ss(input);
    while (ss >> num) {
        A.push_back(num);
    }

    // Checking if the second element is less than or equal to the third element or if the fourth element is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        cout << 0 << endl; // If either condition is true, print 0
    } else {
        // Sorting the vector
        sort(A.begin(), A.end());
        // Printing the difference between the third and second elements
        cout << A[2] - A[1] << endl;
    }

    return 0;
}
