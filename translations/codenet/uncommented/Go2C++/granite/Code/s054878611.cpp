
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> a) {
        vector<int> memo(1e5 + 2, 0);
        for (int num : a) {
                memo[num]++;
                memo[num+1]++;
                memo[num+2]++;
        }
        int out = 0;
        for (int num : memo) {
                if (num > 0) {
                        out = max(out, num);
                }
        }
        return out;
}

int max(int x, int y) {
        if (x > y) {
                return x;
        }
        return y;
}

int main() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
                cin >> a[i];
        }
        cout << solution(n, a) << endl;
        return 0;
}

