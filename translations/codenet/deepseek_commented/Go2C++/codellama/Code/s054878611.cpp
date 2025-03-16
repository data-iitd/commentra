
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> a) {
        int memo[100002] = {0};
        for (int i = 0; i < n; i++) {
                memo[a[i]]++;
                memo[a[i]+1]++;
                memo[a[i]+2]++;
        }
        int out = 0;
        for (int i = 0; i < 100002; i++) {
                if (memo[i] > 0) {
                        out = max(out, memo[i]);
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

