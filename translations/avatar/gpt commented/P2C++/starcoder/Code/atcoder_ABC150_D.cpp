#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, num;
    cin >> n >> num;
    set<int> num_set;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num_set.insert(temp);
    }
    set<int> two_times_set;
    for (int i : num_set) {
        for (int j = 0; j < 30; j++) {
            i /= 2;
            if (i % 2!= 0) {
                two_times_set.insert(j);
                break;
            }
        }
        if (two_times_set.size()!= 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    int num_list[num_set.size()];
    int index = 0;
    for (int i : num_set) {
        num_list[index++] = i;
    }
    int lcm = num_list[0];
    for (int i = 1; i < num_set.size(); i++) {
        lcm = lcm * num_list[i] / __gcd(lcm, num_list[i]);
    }
    cout << (num - lcm / 2) / lcm + 1 << endl;
    return 0;
}

