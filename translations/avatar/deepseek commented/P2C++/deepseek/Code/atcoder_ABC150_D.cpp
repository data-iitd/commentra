#include <iostream>
#include <vector>
#include <numeric> // for std::gcd

using namespace std;

int main() {
    int n, num;
    cin >> n >> num;

    vector<int> num_set(n);
    for (int i = 0; i < n; ++i) {
        cin >> num_set[i];
    }

    // Initialize an empty set to store the number of times each integer is divisible by 2
    vector<int> two_times_set;

    // Loop through each integer in the num_set
    for (int i : num_set) {
        // Divide the integer by 2 repeatedly until it is no longer even
        int count = 0;
        while (i % 2 == 0) {
            i /= 2;
            ++count;
        }
        // Add the count to two_times_set
        two_times_set.push_back(count);
    }

    // If two_times_set contains more than one element, print 0 and break
    bool all_same = true;
    for (size_t i = 1; i < two_times_set.size(); ++i) {
        if (two_times_set[i] != two_times_set[0]) {
            all_same = false;
            break;
        }
    }
    if (!all_same) {
        cout << 0 << endl;
        return 0;
    }

    // If the loop completes, calculate the LCM of the integers in num_set
    int lcm = num_set[0];
    for (int i = 1; i < n; ++i) {
        lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);
    }

    // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}
