
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int num_g = 0, num_p = 0, score = 0;

    for (char x : s) {
        if (x == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                num_g += 1;
            }
        } else if (x == 'p') {
            if (num_g - num_p > 0) {
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }

    cout << score << endl;

    return 0;
}

