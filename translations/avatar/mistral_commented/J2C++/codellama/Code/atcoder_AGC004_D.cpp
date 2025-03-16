
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

class Calculator {
    private:
        int k;
        int answer = 0;
        bool isCalculate = false;
        vector<list<int>> lists;

    public:
        Calculator(int n, int k, vector<int> as) {
            this->k = k;
            lists = vector<list<int>>(n);

            for (int i = 0; i < n; i++) {
                lists[i] = list<int>();
            }

            for (int i = 0; i < n; i++) {
                int j = as[i];
                if (0 < i) {
                    lists[j].push_back(i);
                } else if (0 < j) {
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

    private:
        int dfs(int a, int pre) {
            int h = 0;

            for (int i : lists[a]) {
                h = max(h, dfs(i, a));
            }

            if (0 < pre && h == k - 1) {
                h = 0;
                answer++;
            } else {
                h++;
            }

            return h;
        }
};

int main() {
    int n;
    int k;
    vector<int> as;

    cin >> n >> k;
    as = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    cout << Calculator(n, k, as).calculate() << endl;

    return 0;
}

