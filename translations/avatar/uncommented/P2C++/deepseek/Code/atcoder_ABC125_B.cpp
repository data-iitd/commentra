#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> V(N);
    std::vector<int> C(N);
    std::string line;
    
    std::getline(std::cin, line); // To consume the newline character
    std::getline(std::cin, line);
    std::stringstream ss(line);
    for (int i = 0; i < N; ++i) {
        ss >> V[i];
    }
    
    std::getline(std::cin, line);
    std::stringstream ss2(line);
    for (int i = 0; i < N; ++i) {
        ss2 >> C[i];
    }
    
    std::vector<int> list = {0};
    int ans = 0;
    int X = 0;
    int Y = 0;
    for (int i = 0; i < N; ++i) {
        if (V[i] - C[i] > 0) {
            X = V[i];
            Y = C[i];
            list.push_back(X - Y);
        }
    }
    for (int i = 0; i < list.size(); ++i) {
        ans += list[i];
    }
    std::cout << ans << std::endl;
    
    return 0;
}

