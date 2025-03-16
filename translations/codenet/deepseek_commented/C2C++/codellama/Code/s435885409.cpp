#include <iostream>
#include <string>

using namespace std;

int calc_score() {
    int out = 0;
    string str;
    int score = 0;
    int base = 0;

    // Read the number of outs and update the score and base accordingly
    while (out < 3) {
        cin >> str;
        if (str == "OUT") {
            out++;
        } else if (str == "HIT") {
            if (base == 3) {
                score++;
            } else {
                base++;
            }
        } else if (str == "HOMERUN") {
            score += (base + 1);
            base = 0;
        }
    }

    return score;
}

int main() {
    int n;
    int inning = 0;

    cin >> n;

    // Loop through each inning and calculate the score
    while (inning < n) {
        cout << calc_score() << endl;
        inning++;
    }

    return 0;
}

