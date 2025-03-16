#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> get_nums(int num, int t) {
    vector<int> result;
    for (int i = 0; i < num; ++i) {
        int quotient = t / num;
        if (i < t % num) {
            result.push_back(quotient + 1);
        } else {
            result.push_back(quotient);
        }
    }
    return result;
}

int main() {
    int n, k, l, r, sa, sk;
    cin >> n >> k >> l >> r >> sa >> sk;

    vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);

    stringstream ss;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) {
            ss << " ";
        }
        ss << ans[i];
    }
    cout << ss.str() << endl;

    return 0;
}
