

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // Taking an integer input `n` which represents the number of elements.
    vector<int> t(n + 1), a(n + 1), cnt(n + 1, 0), ans;  // Initializing vectors `t`, `a`, `cnt`, and `ans`.
    for (int i = 1; i <= n; i++) {
        cin >> t[i];  // Taking a list of integers `t` as input.
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];  // Taking another list of integers `a` as input.
        cnt[a[i]]++;  // Counting the occurrences of each element in `a` and storing them in `cnt`.
    }
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
            vector<int> crt = {i};  // Starting a vector `crt` with `i`.
            int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
            while (cnt[x] == 1) {  // Finding the cycle by following the `a` list until reaching an element whose count is not 1.
                crt.push_back(x);
                x = a[x];
            }
            if (crt.size() > ans.size()) {  // Updating `ans` if the length of `crt` is greater than the length of `ans`.
                ans = crt;
            }
        }
    }
    reverse(ans.begin(), ans.end());  // Reversing `ans` to get the correct order of elements in the cycle.
    cout << ans.size() << endl;  // Printing the length of `ans`.
    for (int i : ans) {  // Printing the elements of `ans`.
        cout << i << " ";
    }
    cout << endl;  // Ending the line with a newline character.
    return 0;
}

