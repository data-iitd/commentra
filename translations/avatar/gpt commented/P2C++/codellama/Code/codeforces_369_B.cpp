#include <iostream>
#include <vector>

using namespace std;

vector<int> get_nums(int num, int t) {
    // Generate a list of numbers based on the distribution of t across num parts
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
    // Read input values for n, k, l, r, sa, and sk
    int n, k, l, r, sa, sk;
    cin >> n >> k >> l >> r >> sa >> sk;

    // Calculate the distribution of sk among k parts and sa - sk among the remaining n - k parts
    vector<int> ans = get_nums(k, sk) + get_nums(n - k, sa - sk);

    // Print the result as a space-separated string
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

