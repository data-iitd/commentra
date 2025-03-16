#include <iostream>
#include <vector>
#include <algorithm>

struct Work {
    int time;
    int limit;
};

bool compare(const Work& a, const Work& b) {
    return a.limit < b.limit;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Work> ws(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ws[i].time >> ws[i].limit;
    }
    std::sort(ws.begin(), ws.end(), compare);

    int64_t sum = 0;
    for (const auto& w : ws) {
        sum += w.time;
        if (sum > w.limit) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
    return 0;
}
