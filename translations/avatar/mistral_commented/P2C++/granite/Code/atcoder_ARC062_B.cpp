
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int num_g = 0, num_p = 0;
    int score = 0;

    for (char x : s) {
        if (x == 'g') {
            if (num_g - num_p > 0) {
                score += 1;
                num_p += 1;
            } else {
                score = score;
                num_g += 1;
            }
        } else if (x == 'p') {
            if (num_g - num_p > 0) {
                score = score;
                num_p += 1;
            } else {
                score -= 1;
                num_g += 1;
            }
        }
    }

    std::cout << score << std::endl;

    return 0;
}

