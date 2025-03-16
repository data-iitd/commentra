
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> H(N);
    vector<bool> ans(N, true);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        temp1--;
        temp2--;
        if (H[temp1] < H[temp2]) {
            ans[temp1] = false;
        } else if (H[temp1] > H[temp2]) {
            ans[temp2] = false;
        } else {
            ans[temp1] = false;
            ans[temp2] = false;
        }
    }
    int ans2 = count(ans.begin(), ans.end(), true);
    cout << ans2 << endl;
    return 0;
}
//END-OF-CODE