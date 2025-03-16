#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<int, std::string> map;

    for (int i = 0; i < N; i++) {
        int key = i;
        std::string value;
        std::cin >> value;
        map[key] = value;
    }

    bool ans = true;
    std::unordered_map<int, std::string> past;
    std::string next = "";

    for (int i = 0; i < N; i++) {
        if (past.find(i) != past.end()) {
            ans = false;
            break;
        }
        past[i] = map[i];

        if (i != 0) {
            if (next != map[i].substr(0, 1)) {
                ans = false;
                break;
            }
        }
        next = map[i].substr(map[i].length() - 1, 1);
    }

    if (ans) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

