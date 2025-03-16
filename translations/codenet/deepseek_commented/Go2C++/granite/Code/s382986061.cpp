
#include <iostream>
#include <map>

int main() {
    int N, K;
    std::cin >> N >> K;
    std::map<int, int> as;
    for (int i = 1; i <= N; i++) {
        as[i] = 0;
    }
    for (int i = 0; i < K; i++) {
        int d;
        std::cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            std::cin >> a;
            as[a]++;
        }
    }
    int ans = 0;
    for (auto& [_, v] : as) {
        if (v == 0) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

