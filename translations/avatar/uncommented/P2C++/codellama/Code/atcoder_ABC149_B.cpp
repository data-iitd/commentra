
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string input;
    cin >> input;
    vector<int> cookies;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != ' ') {
            cookies.push_back(input[i] - '0');
        }
    }
    int leftOver = cookies[0] - cookies[2];
    int takahashi = max(0, leftOver);
    cout << takahashi << ' ' << (takahashi > 0 ? cookies[1] : max(0, cookies[1] - abs(leftOver)));
    return 0;
}

