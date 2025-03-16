
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int rNum = 0, gNum = 0, bNum = 0;
    for (char c : S) {
        if (c == 'R') rNum++;
        else if (c == 'G') gNum++;
        else if (c == 'B') bNum++;
    }

    int sum = 0;
    for (int step = 1; step <= ceil(N / 2.0); step++) {
        string s = "";
        for (int i = 0; i < 3; i++) {
            s += S[i + step - 1];
        }
        if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
            sum++;
        }
    }

    cout << rNum * gNum * bNum - sum << endl;

    return 0;
}
