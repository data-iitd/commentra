#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, l, r, sa, sk;
    cin >> n >> k >> l >> r >> sa >> sk;

    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(sk);
    }
    for (int i = 0; i < n - k; i++) {
        ans.push_back(sa - sk);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

