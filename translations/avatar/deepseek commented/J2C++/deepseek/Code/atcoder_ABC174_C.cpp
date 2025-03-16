#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int readInt() {
    static string line;
    static stringstream ss;
    static bool initialized = false;
    if (!initialized) {
        getline(cin, line);
        ss.str(line);
        initialized = true;
    }
    int value;
    ss >> value;
    return value;
}

int solve() {
    int K = readInt();

    // Check if K is divisible by 2 or 5, return -1 if true.
    if (K % 2 == 0 || K % 5 == 0)
        return -1;

    // If K is divisible by 7, divide K by 7.
    if (K % 7 == 0)
        K /= 7;

    // Multiply K by 9.
    K *= 9;

    // Initialize the answer and the remainder.
    int ans = 1;
    int remainder = 10 % K;

    // Loop to find the number of digits required to form a number that is a multiple of K.
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
