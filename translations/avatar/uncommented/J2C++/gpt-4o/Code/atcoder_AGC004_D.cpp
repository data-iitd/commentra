#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

class Calculator {
private:
    int k;
    int answer = 0;
    bool isCalculate = false;
    std::vector<std::vector<int>> lists;

public:
    Calculator(int n, int k, const std::vector<int>& as) : k(k), lists(n) {
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (i > 0) {
                lists[j].push_back(i);
            } else if (j > 0) {
                answer++;
            }
        }
    }

    int calculate() {
        if (!isCalculate) {
            dfs(0, 0);
            isCalculate = true;
        }
        return answer;
    }

private:
    int dfs(int a, int pre) {
        int h = 0;
        for (int i : lists[a]) {
            h = std::max(h, dfs(i, a));
        }
        if (pre > 0 && h == k - 1) {
            h = 0;
            answer++;
        } else {
            h++;
        }
        return h;
    }
};

void run() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];
        as[i]--; // Adjusting to 0-based index
    }
    Calculator calculator(n, k, as);
    std::cout << calculator.calculate() << std::endl;
}

int main() {
    std::thread t(run);
    t.join();
    return 0;
}

// <END-OF-CODE>
