#include <iostream>
#include <set>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

int main() {
    // Taking input of n and number of distinct numbers
    int n, num;
    cin >> n >> num;

    // Creating a set of distinct numbers
    set<int> num_set;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num_set.insert(x);
    }

    // Finding the powers of 2 that appear exactly twice in the binary representation of each number in num_set
    set<int> two_times_set;
    for (int i : num_set) {
        // Initializing a counter to keep track of the number of times 2 is divided
        int power_of_two = 0;

        // Dividing i by 2 repeatedly until it is no longer odd
        while (i % 2 == 0) {
            power_of_two++;
            i /= 2;
        }

        // If the number of times 2 is divided is not exactly 1, then the answer is 0
        if (power_of_two > 1) {
            cout << 0 << endl;
            return 0;
        }

        // Add the power of 2 to two_times_set
        two_times_set.insert(power_of_two);
    }

    // If the size of two_times_set is not exactly 1, then the answer is 0
    if (two_times_set.size() != 1) {
        cout << 0 << endl;
        return 0;
    }

    // Finding the least common multiple of all numbers in num_set
    vector<int> num_list(num_set.begin(), num_set.end());
    int lcm = num_list[0];

    // Finding the least common multiple of the first number and the next number
    for (size_t i = 1; i < num_list.size(); ++i) {
        lcm = lcm * num_list[i] / std::gcd(lcm, num_list[i]);
    }

    // Printing the answer
    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}

// <END-OF-CODE>
