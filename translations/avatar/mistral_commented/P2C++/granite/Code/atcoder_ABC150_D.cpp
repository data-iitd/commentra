
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    cin >> n >> num;

    set<int> num_set;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        num_set.insert(temp);
    }

    set<int> two_times_set;
    for (auto i : num_set) {
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

    if (two_times_set.size()!= 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> num_list(num_set.begin(), num_set.end());
    int lcm = num_list[0];
    for (int i = 1; i < num_list.size(); i++) {
        lcm = (lcm * num_list[i]) / __gcd(lcm, num_list[i]);
    }

    cout << (num - lcm / 2) / lcm + 1 << endl;

    return 0;
}
