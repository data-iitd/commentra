#include <iostream>
#include <string>

int calc_score() {
    int out = 0;
    std::string str;
    int score = 0;
    int base = 0;

    while (out < 3) {
        std::cin >> str;
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

int main(void) {
    int n;
    int inning = 0;

    std::cin >> n;

    while (inning < n) {
        std::cout << calc_score() << std::endl;
        inning++;
    }

    return 0;
}

