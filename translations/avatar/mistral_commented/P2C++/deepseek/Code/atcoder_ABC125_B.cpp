#include <iostream>
#include <vector>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::cin.ignore(); // To ignore the newline character after N

    std::vector<int> V(N);
    std::vector<int> C(N);

    std::string line;
    std::getline(std::cin, line);
    std::istringstream streamV(line);
    for (int i = 0; i < N; ++i) {
        streamV >> V[i];
    }

    std::getline(std::cin, line);
    std::istringstream streamC(line);
    for (int i = 0; i < N; ++i) {
        streamC >> C[i];
    }

    std::vector<int> list;
    int ans = 0;
    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; ++i) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            list.push_back(X - Y);
            ans += X - Y;
        }
    }

    std::cout << std::accumulate(list.begin(), list.end(), 0) << std::endl;
    std::cout << ans << std::endl;

    return 0;
}
