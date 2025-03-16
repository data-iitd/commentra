#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto read = []() {
        std::vector<int> values;
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            values.push_back(value);
        }
        return values;
    };

    auto R = read;

    std::vector<int> input = R();
    int n = input[0], m = input[1], s = input[2], f = input[3];

    std::string direction = (s < f) ? "R" : "L";
    std::string res = "";

    int i = 1;
    int j = s;

    input = R();
    int t = input[0], l = input[1], r = input[2];

    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            input = R();
            t = input[0];
            l = input[1];
            r = input[2];
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + (s < f ? 1 : -1) && j + (s < f ? 1 : -1) <= r)) {
            res += 'X';
        } else {
            res += direction[0];
            j += (s < f ? 1 : -1);
        }
        i++;
    }

    std::cout << res << '\n';

    return 0;
}
