#include <iostream>
#include <set>
#include <vector>
#include <numeric> // For std::gcd
using namespace std;

int main() {
    // Read two integers from input: n (an upper limit) and num (a number to be processed)
    int n, num;
    cin >> n >> num;

    // Read a set of integers from input and convert them to a set to ensure uniqueness
    set<int> num_set;
    int x;
    while (cin >> x) {
        num_set.insert(x);
    }

    // Initialize an empty set to store values related to the two times condition
    set<int> two_times_set;

    // Iterate through each number in the unique set
    for (int i : num_set) {
        int temp = i;
        // Check how many times the number can be divided by 2
        for (int j = 1; j < 30; j++) {
            temp /= 2; // Divide the number by 2
            if (temp % 2 != 0) { // Check if the result is odd
                two_times_set.insert(j); // Add the count of divisions to the set
                break; // Exit the inner loop if an odd number is found
            }
        }

        // If more than one unique count of divisions by 2 is found, print 0 and exit
        if (two_times_set.size() != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    // If the loop completes without breaking, proceed to calculate the least common multiple (LCM)
    vector<int> num_list(num_set.begin(), num_set.end()); // Convert the set back to a vector for processing
    long long lcm = num_list[0]; // Initialize LCM with the first element of the vector

    // Calculate the LCM of all numbers in the vector
    for (size_t i = 1; i < num_list.size(); i++) {
        lcm = lcm * num_list[i] / gcd(lcm, num_list[i]); // Update LCM using the GCD
    }

    // Calculate and print the final result based on the LCM and the input number
    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}

// <END-OF-CODE>
