
#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::string>> q;

    for (int i = 0; i < n; i++) {
        std::vector<std::string> a;
        std::string temp;
        while (std::cin >> temp) {
            a.push_back(temp);
        }
        q.push_back(a);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (q[i][0] == q[j][q[j].size() - 1]) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}

