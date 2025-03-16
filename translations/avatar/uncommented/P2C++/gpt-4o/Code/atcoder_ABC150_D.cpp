#include <iostream>
#include <set>
#include <vector>
#include <numeric> // for std::gcd
using namespace std;

int main() {
    int n, num;
    cin >> n >> num;
    set<int> num_set;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        num_set.insert(x);
    }

    set<int> two_times_set;
    for (int i : num_set) {
        int temp = i;
        for (int j = 1; j < 30; ++j) {
            temp /= 2;
            if (temp % 2 != 0) {
                two_times_set.insert(j);
                break;
            }
        }
        if (two_times_set.size() != 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<int> num_list(num_set.begin(), num_set.end());
    long long lcm = num_list[0];
    for (size_t i = 1; i < num_list.size(); ++i) {
        lcm = lcm * num_list[i] / std::gcd(lcm, num_list[i]);
    }
    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}

// <END-OF-CODE>
