#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> cookies;
    int input;
    while (cin >> input) {
        cookies.push_back(input);
    }
    int leftOver = cookies[0] - cookies[2];
    int takahashi = max(0, leftOver);
    cout << takahashi << ' ' << (takahashi > 0 ? to_string(cookies[1]) : to_string(max(0, cookies[1] - abs(leftOver)))) << endl;
    return 0;
}

