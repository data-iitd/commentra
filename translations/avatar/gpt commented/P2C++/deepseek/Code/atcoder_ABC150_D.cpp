#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>  // Include the numeric library for the GCD function

using namespace std;

int main() {
    int n, num;
    cin >> n >> num;

    set<int> num_set;
    int temp;
    while (cin >> temp) {
        num_set.insert(temp);
    }

    set<int> two_times_set;

    for (int i : num_set) {
        int count = 0;
        while (i % 2 == 0) {
            i /= 2;
            count++;
        }
        two_times_set.insert(count);
    }

    if (two_times_set.size() != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> num_list(num_set.begin(), num_set.end());
    int lcm = num_list[0];

    for (int i = 1; i < num_list.size(); i++) {
        lcm = lcm * num_list[i] / gcd(lcm, num_list[i]);
    }

    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}
