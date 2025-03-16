
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long> list;
    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;
        list.push_back(x);
    }
    vector<long> odd;
    long sum = 0;
    for (long x : list) {
        if (x % 2 == 0) {
            sum += x;
        } else {
            odd.push_back(x);
        }
    }
    sort(odd.begin(), odd.end());
    for (long x : odd) {
        sum += x;
    }
    if (odd.size() % 2 != 0) {
        sum -= odd[0];
    }
    cout << sum << endl;
    return 0;
}

