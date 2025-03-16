#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string TenToN(int number, int n) {
    string s;
    int tmp = number;
    while (true) {
        s = to_string(tmp % n) + s;
        if (tmp < n) break;
        tmp /= n;
    }
    return s;
}

int main() {
    int N, K;
    cin >> N >> K;
    string s = TenToN(N, K);
    cout << s.length() << endl;
    return 0;
}

