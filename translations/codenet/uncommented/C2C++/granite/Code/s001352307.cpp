
#include <iostream>

using namespace std;

int main() {
	int i, j;
	int ans[1024][2];
	int t;

	for(t = 0; ; t++) {
		for(i = 0; i < 1024; i++) {
			ans[i][0] = 0;
			ans[i][1] = 0;
		}

		int W, N;
		cin >> W >> N;
		if(W == 0)
			break;
		for(i = 0; i < N; i++)
			cin >> ans[i][0] >> ans[i][1];

		for(i = 0; i < N; i++) {
			for(j = 1023; j >= ans[i][1]; j--) {
				if(ans[j][0] < ans[i][0] + ans[j - ans[i][1]][0]) {
					ans[j][0] = ans[i][0] + ans[j - ans[i][1]][0];
					ans[j][1] = ans[i][1] + ans[j - ans[i][1]][1];
				}
			}
		}

		for(j = 0; ans[W][0] == ans[W - j - 1][0]; j++);

		cout << "Case " << t + 1 << ":" << endl;
		cout << ans[W - j][0] << endl;
		cout << ans[W - j][1] << endl;
	}

	return 0;
}

