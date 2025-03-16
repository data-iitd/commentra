#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int rNum = 0;
    int gNum = 0;
    int bNum = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') {
            rNum++;
        } else if (S[i] == 'G') {
            gNum++;
        } else if (S[i] == 'B') {
            bNum++;
        }
    }

    int sum = 0;
    for (int step = 1; step <= ceil(N / 2.0); step++) {
        string s = S[step - 1] + S[step] + S[step + 1];
        if (s == "RGB" || s == "RBG" || s == "BGR" || s == "BRG" || s == "GBR" || s == "GRB") {
            sum++;
        }
    }

    cout << rNum * gNum * bNum - sum << endl;

    return 0;
}

