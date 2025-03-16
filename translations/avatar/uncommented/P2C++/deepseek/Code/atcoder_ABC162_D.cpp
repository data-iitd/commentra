#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void calculate(int n, string s) {
    vector<char> arr(s.begin(), s.end());
    int rNum = 0, gNum = 0, bNum = 0;
    for (char c : arr) {
        if (c == 'R') rNum++;
        else if (c == 'G') gNum++;
        else if (c == 'B') bNum++;
    }
    int sum = 0;
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        for (int i = 0; i <= n - 2 * step; i++) {
            string s = string() + arr[i] + arr[i + step] + arr[i + step * 2];
            if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
                sum++;
            }
        }
    }
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    calculate(N, S);
    return 0;
}

