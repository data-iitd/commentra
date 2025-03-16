#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int solve() {
    int N;
    std::cin >> N;

    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    int sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;

    for (int i = 0; i < arr.size(); ++i) {
        q.push(arr[i]);

        if (arr[i] <= q.top()) {
            ++sum;
        }
    }

    return sum;
}

int main() {
    std::cout << solve() << std::endl;
    return 0;
}

