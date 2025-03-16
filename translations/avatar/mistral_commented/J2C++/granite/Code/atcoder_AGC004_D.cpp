

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Calculator {
private:
    int k;
    int answer = 0;
    bool isCalculate = false;
    vector<vector<int>> lists;

public:
    Calculator(int n, int k, vector<int> as) {
        this->k = k;
        lists.resize(n);

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
            dfs(0, -1);
            isCalculate = true;
        }
        return answer;
    }

    int dfs(int a, int pre) {
        int h = 0;

        for (int i : lists[a]) {
            h = max(h, dfs(i, a));
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

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        as[i]--;
    }

    Calculator calc(n, k, as);
    cout << calc.calculate() << endl;

    return 0;
}

