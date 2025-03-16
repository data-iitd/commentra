
#include <iostream>
#include <vector>

using namespace std;

vector<int> get_nums(int num, int t) {
    vector<int> ans;
    for (int i = 0; i < num; i++) {
        ans.push_back(t // num + 1 if i in range(t % num) else t // num);
    }
    return ans;
}

int main() {
    int n, k, l, r, sa, sk;
    cin >> n >> k >> l >> r >> sa >> sk;
    vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

