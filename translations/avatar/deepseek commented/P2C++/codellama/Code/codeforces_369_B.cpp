#include <iostream>
#include <vector>

using namespace std;

vector<int> get_nums(int num, int t) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    vector<int> ans;
    for (int i = 0; i < num; i++) {
        if (i < t % num) {
            ans.push_back(t / num + 1);
        } else {
            ans.push_back(t / num);
        }
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
    cout << endl;

    return 0;
}

