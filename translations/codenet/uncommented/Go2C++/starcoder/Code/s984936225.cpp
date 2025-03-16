#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	cin >> N >> M;
	int Inf = 1 << 62;
	// +-ある数は先頭が変わるので - 1,でシフトする前の段階で1ビット使ってるので -1より 62が最大
	// vertex := make([]int,N)
	int a[M],b[M],c[M];
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
		c[i] = -c[i];
	}
	// fmt.Println(Inf)
	int dist[N]; //ここにコストをいれる　その地点にいくまでのこすとを考える
	for (int i = 0; i < N; i++) {
		dist[i] = Inf;//考えうる最大値を考える
	}
	dist[0] = 0; //最初は0にいるので
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				//dist[b[i]-1]の行くまでがdist[a[i]-1] + cos　よりもかかるなら最小のほうにする
				dist[b[i]-1] = dist[a[i]-1] + c[i];
			}
		}
	}
	int ans = dist[N-1]; //最小値が存在する場合はansが答え
	bool navigate[N];
	for (int loop = 0; loop < N; loop++) {
		for (int i = 0; i < M; i++) {
			if (dist[a[i]-1] == Inf) {
				continue;
			}
			if (dist[b[i]-1] > dist[a[i]-1] + c[i]) {
				dist[b[i]-1] = dist[a[i]-1] + c[i];
				navigate[b[i]-1] = true;
			}
			if (navigate[a[i]-1] == true) {
				navigate[b[i]-1] = true;
			}
		}
	}

	if (navigate[N-1]) {
		cout << "inf" << endl;
	} else {
		cout << -ans << endl;
	}

}

