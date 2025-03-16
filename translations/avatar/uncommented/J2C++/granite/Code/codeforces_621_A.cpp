
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> list;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        list.push_back(num);
    }
    vector<long long> odd;
    long long sum = 0;
    for (long long i : list) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            odd.push_back(i);
        }
    }
    sort(odd.begin(), odd.end());
    for (long long i : odd) {
        sum += i;
    }
    if (odd.size() % 2!= 0) {
        sum -= odd[0];
    }
    cout << sum << endl;
    return 0;
}
//END-OF-CODE