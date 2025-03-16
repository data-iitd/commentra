#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for std::accumulate

class Task {
public:
    int solve(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> sorted = arr;
        std::sort(sorted.begin(), sorted.end());

        long long total = static_cast<long long>(n) * (n + 1) / 2;
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int target = sorted[mid];
            long long cnt = 0;
            std::vector<long long> bit(2 * n + 2, 0);

            for (int x = n + 1; x < bit.size(); x += x & -x) {
                bit[x]++;
            }

            for (int i = 0; i < n; i++) {
                int cur = 0;
                if (arr[i] <= target) {
                    cur = 1;
                } else {
                    cur = -1;
                }
                for (int x = cur + n + 1; x < bit.size(); x += x & -x) {
                    bit[x]++;
                }
                for (int x = cur + n; x > 0; x -= x & -x) {
                    cnt += bit[x];
                }
            }

            if (cnt >= total / 2 + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return sorted[l];
    }
};

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    Task tsk;
    std::cout << tsk.solve(arr) << std::endl;

    return 0;
}

