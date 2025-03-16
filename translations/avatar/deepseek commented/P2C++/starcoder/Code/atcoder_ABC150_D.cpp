
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read the input values for n and num
    int n, num;
    cin >> n >> num;

    // Read the set of integers
    set<int> num_set;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num_set.insert(temp);
    }

    // Initialize an empty set to store the number of times each integer is divisible by 2
    set<int> two_times_set;

    // Loop through each integer in the num_set
    for (int i : num_set) {
        // Divide the integer by 2 repeatedly until it is no longer even
        for (int j = 1; j < 30; j++) {
            i /= 2;
            if (i % 2!= 0) {
                // Add the count to two_times_set
                two_times_set.insert(j);
                break;
            }
        }
        // If two_times_set contains more than one element, print 0 and break
        if (two_times_set.size()!= 1) {
            cout << 0 << endl;
            break;
        }
    } else {
        // If the loop completes, calculate the LCM of the integers in num_set
        vector<int> num_list(num_set.begin(), num_set.end());
        int lcm = num_list[0];
        for (int i = 1; i < num_list.size(); i++) {
            lcm = lcm * num_list[i] / __gcd(lcm, num_list[i]);
        }

        // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
        cout << (num - lcm / 2) / lcm + 1 << endl;
    }

    return 0;
}

