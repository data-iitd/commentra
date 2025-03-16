#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read the number of test cases from the input
    int n;
    cin >> n;

    // Initialize an empty vector to store the given numbers
    vector<int> w;

    // Read the given numbers and store them in the vector
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        w.push_back(number);
    }

    // Initialize a variable 'c' with a value of 2
    int c = 2;

    // Iterate through each number in the vector 'w'
    for (int number : w) {

        // If the number is equal to 1, print the current value of 'c'
        if (number == 1) {
            cout << c << endl;
        }

        // If the number is even, toggle the value of 'c'
        else if (number % 2 == 0) {
            c = 3 - c;
            cout << c << endl;
        }

        // If the number is odd, print the current value of 'c'
        else {
            cout << c << endl;
        }
    }

    return 0;
}

