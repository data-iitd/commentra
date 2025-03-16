
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> cookies;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cookies.push_back(x);
    }
    int leftOver = cookies[0] - cookies[2];
    int takahashi = max(0, leftOver);
    cout << takahashi << ' ' << (takahashi > 0 ? cookies[1] : max(0, cookies[1] - abs(leftOver))) << endl;
    return 0;
}

