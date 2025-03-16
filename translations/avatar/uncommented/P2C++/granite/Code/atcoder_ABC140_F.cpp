
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), greater<int>());
    vector<bool> flag(N, true);
    vector<int> cur;
    cur.push_back(S[0]);
    flag[0] = false;
    for (int i = 0; i < N; i++) {
        int j = 0;
        int jM = cur.size();
        for (int k = 0; k < N; k++) {
            if (flag[k] && S[k] < cur[j]) {
                cur.push_back(S[k]);
                j++;
                flag[k] = false;
                if (j == jM) {
                    break;
                }
            }
        }
        if (j == jM) {
            cout << "No" << endl;
            return 0;
        }
        sort(cur.begin(), cur.end(), greater<int>());
    }
    cout << "Yes" << endl;
    return 0;
}
