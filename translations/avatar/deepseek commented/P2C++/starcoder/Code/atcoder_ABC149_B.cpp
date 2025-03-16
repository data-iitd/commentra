
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> cookies;
    int leftOver;
    int takahashi;

    cin >> cookies[0] >> cookies[1] >> cookies[2];
    leftOver = cookies[0] - cookies[2];
    takahashi = max(0, leftOver);
    cout << takahashi << " " << (cookies[1] if takahashi > 0 else max(0, cookies[1] - abs(leftOver))) << endl;

    return 0;
}

