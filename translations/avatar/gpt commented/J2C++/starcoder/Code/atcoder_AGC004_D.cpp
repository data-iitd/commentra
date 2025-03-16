#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Calculator {
private:
    int k;
    int answer;
    bool isCalculate;
    vector<vector<int>> lists;

public:
    Calculator(int n, int k, vector<int> as) {
        this->k = k;
        this->answer = 0;
        this->isCalculate = false;
        this->lists = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            this->lists[i] = vector<int>();
        }
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (0 < i) {
                this->lists[j].push_back(i);
            } else if (0 < j) {
                this->answer++;
            }
        }
    }

    int calculate() {
        if (!this->isCalculate) {
            this->dfs(0, 0);
            this->isCalculate = true;
        }
        return this->answer;
    }

    int dfs(int a, int pre) {
        int h = 0;
        for (int i : this->lists[a]) {
            h = max(h, this->dfs(i, a));
        }
        if (0 < pre && h == this->k - 1) {
            h = 0;
            this->answer++;
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
    }
    Calculator calculator(n, k, as);
    cout << calculator.calculate() << endl;
    return 0;
}

