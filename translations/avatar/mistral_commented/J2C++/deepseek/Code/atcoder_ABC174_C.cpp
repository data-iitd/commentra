#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int readInt() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    ss >> num;
    return num;
}

int solve() {
    int K = readInt();

    if (K % 2 == 0 || K % 5 == 0) return -1;

    if (K % 7 == 0) K /= 7;
    K *= 9;

    int ans = 1, remainder = 10 % K;

    while (remainder != 1) {
        ans++;
        remainder = (remainder * 10) % K;
    }

    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}

