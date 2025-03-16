

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
        this->lists.resize(n);
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (i > 0) {
                this->lists[j].push_back(i);
            } else if (j > 0) {
                this->answer++;
            }
        }
    }

    int calculate() {
        if (!this.isCalculate) {
            this->dfs(0, 0);
            this->isCalculate = true;
        }
        return this->answer;
    }

    int dfs(int a, int pre) {
        int h = 0;
        for (int i : this.lists[a]) {
            h = max(h, this.dfs(i, a));
        }
        if (pre > 0 && h == this.k - 1) {
            h = 0;
            this->answer++;
        } else {
            h++;
        }
        return h;
    }
};

int main() {
    int n;
    int k;
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

