#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore();  // To ignore the newline character after N

    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<int> V;
    std::string token;
    while (std::getline(iss, token, ' ')) {
        V.push_back(std::stoi(token));
    }

    std::getline(std::cin, line);
    std::istringstream iss2(line);
    std::vector<int> C;
    while (std::getline(iss2, token, ' ')) {
        C.push_back(std::stoi(token));
    }

    int ans = 0;
    std::vector<int> list = {0};

    for (int i = 0; i < N; ++i) {
        if (V[i] - C[i] > 0) {
            int X = V[i];
            int Y = C[i];
            list.push_back(X - Y);
        }
    }

    for (int num : list) {
        ans += num;
    }

    std::cout << ans << std::endl;

    return 0;
}
