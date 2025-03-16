#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Block {
    std::string Value;
    int Len;
};

std::vector<Block> RunLength(const std::string& s) {
    std::vector<Block> r;
    if (s.empty()) {
        return r;
    }
    Block t = {std::string(1, s[0]), 1};
    for (size_t i = 1; i < s.size(); ++i) {
        if (t.Value == std::string(1, s[i])) {
            t.Len++;
        } else {
            r.push_back(t);
            t = {std::string(1, s[i]), 1};
        }
    }
    r.push_back(t);
    return r;
}

int main() {
    int N, K, ans = 0;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;
    std::vector<Block> blocks = RunLength(S);
    int sum = 0, zero = 0, l = 0;
    for (size_t r = 0; r < blocks.size(); ++r) {
        sum += blocks[r].Len;
        if (blocks[r].Value == "0") {
            zero++;
        }
        while (K < zero) {
            sum -= blocks[l].Len;
            if (blocks[l].Value == "0") {
                zero--;
            }
            l++;
        }
        ans = std::max(ans, sum);
    }
    std::cout << ans << std::endl;
    return 0;
}

