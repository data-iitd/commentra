#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int readInt() {
    static stringstream ss;
    static bool initialized = false;
    if (!initialized) {
        string input;
        getline(cin, input);
        ss.str(input);
        initialized = true;
    }
    int result;
    ss >> result;
    return result;
}

int solve() {
    int K = readInt();
    if (K % 2 == 0 || K % 5 == 0) return -1;
    if (K % 7 == 0) K /= 7;
    K *= 9;
    int ans = 1;
    int remainder = 10 % K;
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
