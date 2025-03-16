#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> orig;
    for (int i = 1; i <= n; i++) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        do {
            orig.push_back(v);
        } while (next_permutation(v.begin(), v.end()));
    }

    vector<int> p, q;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(p));
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(q));

    int pn = distance(orig.begin(), find(orig.begin(), orig.end(), p));
    int qn = distance(orig.begin(), find(orig.begin(), orig.end(), q));

    cout << abs(pn - qn) << endl;

    return 0;
}

