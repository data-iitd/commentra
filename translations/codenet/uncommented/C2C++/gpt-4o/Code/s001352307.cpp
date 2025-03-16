#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int W, N;
    vector<vector<int>> input(1024, vector<int>(2, 0));
    vector<vector<int>> ans(1024, vector<int>(2, 0));

    int t = 0;
    while (true) {
        // Reset ans and input for each case
        fill(ans.begin(), ans.end(), vector<int>(2, 0));
        fill(input.begin(), input.end(), vector<int>(2, 0));

        cin >> W >> N;
        if (W == 0)
            break;

        for (int i = 0; i < N; i++)
            scanf("%d,%d", &input[i][0], &input[i][1]);

        for (int i = 0; i < N; i++) {
            for (int j = 1023; j >= input[i][1]; j--) {
                if (ans[j][0] < input[i][0] + ans[j - input[i][1]][0]) {
                    ans[j][0] = input[i][0] + ans[j - input[i][1]][0];
                    ans[j][1] = input[i][1] + ans[j - input[i][1]][1];
                }
            }
        }

        int j = 0;
        while (ans[W][0] == ans[W - j - 1][0]) {
            j++;
        }

        cout << "Case " << t + 1 << ":\n" << ans[W - j][0] << "\n" << ans[W - j][1] << "\n";
        t++;
    }

    return 0;
}

// <END-OF-CODE>
