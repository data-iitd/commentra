#include <bits/stdc++.h>
using namespace std;

// Function to get a list of numbers separated by a space
vector<int> get_nums_l() {
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] =='') {
            ans.push_back(stoi(s.substr(0, i)));
            s.erase(0, i + 1);
            i = -1;
        }
    }
    ans.push_back(stoi(s));
    return ans;
}

// Function to get a list of numbers of a given length
vector<int> get_nums_n(int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans.push_back(x);
    }
    return ans;
}

// Function to get all integers from a file
vector<int> get_all_int() {
    vector<int> ans;
    int x;
    while (cin >> x) {
        ans.push_back(x);
    }
    return ans;
}

// Function to prime factorize a number
vector<int> prime_factorize(int n) {
    vector<int> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    int f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            ans.push_back(f);
            n /= f;
        } else {
            f += 2;
        }
    }
    if (n!= 1) {
        ans.push_back(n);
    }
    return ans;
}

// Function to calculate the factorial of a number
vector<pair<int, int>> factorial(int n) {
    vector<pair<int, int>> ans;
    if (ans.size() == 0) {
        ans.push_back({n, 1});
    }
    return ans;
}

// Main function
int main() {
    int n;
    cin >> n;
    vector<int> fac = prime_factorize(n);
    int ans = 0;
    for (int p : fac) {
        int x = 0;
        for (int i = 1; i < 1000000000; i++) {
            if (x >= i) {
                x -= i;
                ans += 1;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

