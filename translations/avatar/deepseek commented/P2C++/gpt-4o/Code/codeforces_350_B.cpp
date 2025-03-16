#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;  // Taking an integer input `n` which represents the number of elements.
    
    vector<int> t(n + 1), a(n + 1);
    t[0] = 0;  // Initialize the first element to 0.
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];  // Taking a list of integers `t` as input.
    }
    
    a[0] = 0;  // Initialize the first element to 0.
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];  // Taking another list of integers `a` as input.
    }
    
    vector<int> ans;  // Initializing an empty list `ans`.
    vector<int> cnt(n + 1, 0);  // Initializing a list `cnt` with zeros.

    // Counting the occurrences of each element in `a` and storing them in `cnt`.
    for (int i = 1; i <= n; ++i) {
        cnt[a[i]]++;
    }

    // Iterating over the range from 1 to `n` to find cycles starting from each element.
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
            vector<int> crt;  // Starting a list `crt`.
            crt.push_back(i);  // Adding `i` to `crt`.
            int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
            // Finding the cycle by following the `a` list until reaching an element whose count is not 1.
            while (cnt[x] == 1) {
                crt.push_back(x);
                x = a[x];
            }
            // Updating `ans` if the length of `crt` is greater than the length of `ans`.
            if (crt.size() > ans.size()) {
                ans = crt;  // Copying `crt` to `ans`.
            }
        }
    }

    // Reversing `ans` to get the correct order of elements in the cycle.
    reverse(ans.begin(), ans.end());

    // Printing the length of `ans` and the elements of `ans`.
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");  // Print elements with space.
    }
    cout << endl;

    return 0;
}

// <END-OF-CODE>
