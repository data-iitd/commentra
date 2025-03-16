
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int magic = 1000000007;

int find(int n) {
	for (int i = 0; i < N; i++) {
		if (n == p[i]) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// PARSE HELPER SESSION

	// string STR;
	// cin >> STR;
	// cout << "string " << STR << endl;

	// float F;
	// cin >> F;
	// cout << "float " << F << endl;

	// parsing int array
	int X, N;
	cin >> X >> N;
	// cout << "X " << X << endl;
	// cout << "N " << N << endl;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	// cout << "p " << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << " " << p[4] << " " << p[5] << " " << p[6] << " " << p[7] << " " << p[8] << " " << p[9] << endl;

	for (int i = 0; i <= 100; i++) {
		if (find(X - i) == 1) {
			cout << X - i << endl;
			exit(0);
		}
		if (find(X + i) == 1) {
			cout << X + i << endl;
			exit(0);
		}
	}

	// sort.Sort(sort.Reverse(sort.IntSlice(A[:])))
	// sort.Sort(sort.IntSlice(A[:]))

	// parsing string as byte array
	// var s [10000]byte
	// var si [10000]int
	// str := io.Next()
	// for i := 0; i < len(str); i++ {
	// 	s[i] = str[i]
	//  // "0" = 48, "A" = 65, "a" = 97
	//  si[i] = int(str[i]) - 48
	// }
	// cout << "byte array " << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << " " << s[4] << " " << s[5] << " " << s[6] << " " << s[7] << " " << s[8] << " " << s[9] << endl;

	// OUTPUT GENERATION PART
	// ans := 0
	// cout << ans << endl;

	// if ans > 0 {
	//   cout << "Yes" << endl;
	// } else {
	//   cout << "No" << endl;
	// }

	// BFS/DFS PART
	// visited := []int{}
	// bfs/dfs(1, neighbor, func(node int) {
	// 	visited = append(visited, node)
	// })
	// cout << visited << endl;

	// DFS 2
	// var dp [2000000]int
	// nei := make(map[int][]int)
	// nei[0] = []int{1, 2}
	// nei[1] = []int{0}
	// nei[2] = []int{0, 3}
	// nei[3] = []int{2}
	// dfs2(0, nei, func(n, p int) {
	// 	cout << n << " -> " << p << endl;
	// 	dp[n] = p
	// }, func(n, p int) {
	// 	cout << n << " -> " << p << endl;
	// })
	// cout << dp[0:5] << endl;

	// COMBINATION
	// cout << N << " " << M << " " << intMax(N, M) << endl;
	// cout << "Lucas " << combMod(N, M, 13) << " " << combination(N, M) << endl;
}

int main() {
	solve();
	return 0;
}

