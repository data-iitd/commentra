#include <iostream>
#include <set>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

int main() {
    int n, num;
    cin >> n >> num;

    // Read the set of integers
    set<int> num_set;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num_set.insert(x);
    }

    // Initialize an empty set to store the number of times each integer is divisible by 2
    set<int> two_times_set;

    // Loop through each integer in the num_set
    for (int i : num_set) {
        int count = 0;
        while (i % 2 == 0) {
            i /= 2;
            count++;
        }
        // Add the count to two_times_set
        two_times_set.insert(count);
        
        // If two_times_set contains more than one element, print 0 and break
        if (two_times_set.size() != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    // If the loop completes, calculate the LCM of the integers in num_set
    vector<int> num_list(num_set.begin(), num_set.end());
    long long lcm = num_list[0];
    for (size_t i = 1; i < num_list.size(); ++i) {
        lcm = lcm * num_list[i] / std::gcd(lcm, num_list[i]);
    }

    // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
    cout << (num / lcm) << endl;

    return 0;
}

// <END-OF-CODE>
