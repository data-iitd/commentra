#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric> // for std::gcd

using namespace std;

int main() {
    int n, num;
    cin >> n >> num;

    set<int> num_set;
    vector<int> num_list;

    int x;
    while (cin >> x) {
        num_set.insert(x);
    }

    num_list.assign(num_set.begin(), num_set.end());

    set<int> two_times_set;

    for (int i : num_set) {
        int power_of_two = 0;
        while (i % 2 == 0) {
            power_of_two++;
            i /= 2;
        }
        if (power_of_two > 1) {
            cout << 0 << endl;
            return 0;
        }
        two_times_set.insert(power_of_two);
    }

    if (two_times_set.size() != 1) {
        cout << 0 << endl;
        return 0;
    }

    int lcm = num_list[0];
    for (int i = 1; i < num_list.size(); i++) {
        lcm = lcm * num_list[i] / gcd(lcm, num_list[i]);
    }

    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}
