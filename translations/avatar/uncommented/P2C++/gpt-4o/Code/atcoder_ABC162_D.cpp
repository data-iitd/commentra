#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void calculate(int n, string s) {
    int rNum = count(s.begin(), s.end(), 'R');
    int gNum = count(s.begin(), s.end(), 'G');
    int bNum = count(s.begin(), s.end(), 'B');
    int sum = 0;

    for (int step = 1; step <= ceil(n / 2.0); step++) {
        for (int i = 0; i <= n - 2 * step; i++) {
            string sub = string() + s[i] + s[i + step] + s[i + 2 * step];
            if (sub == "RGB" || sub == "RBG" || sub == "BGR" || sub == "BRG" || sub == "GBR" || sub == "GRB") {
                sum++;
            }
        }
    }
    cout << rNum * gNum * bNum - sum << endl;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    calculate(N, S);
    return 0;
}

// <END-OF-CODE>
