#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n + 1, 0);
    vector<int> a(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    vector<int> ans;

    // Reading the input for list `t`
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    // Reading the input for list `a`
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // Counting the occurrences of each element in `a` and storing them in `cnt`
    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
    }

    // Iterating over the range from 1 to `n` to find cycles starting from each element
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle
            vector<int> crt;
            int x = a[i];
            // Finding the cycle by following the `a` list until reaching an element whose count is not 1
            while (cnt[x] == 1) {
                crt.push_back(x);
                x = a[x];
            }
            // Updating `ans` if the length of `crt` is greater than the length of `ans`
            if (crt.size() > ans.size()) {
                ans = crt;
            }
        }
    }

    // Reversing `ans` to get the correct order of elements in the cycle
    reverse(ans.begin(), ans.end());

    // Printing the length of `ans` and the elements of `ans`
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
