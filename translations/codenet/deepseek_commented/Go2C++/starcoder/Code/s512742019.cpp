#include <bits/stdc++.h>

using namespace std;

// Constants MOD and INF for modular arithmetic and infinite values.
// Mon struct and Mons type for monsters.
const int MOD = int(1e+9) + 7;
const int INF = 1 << 60;

struct Mon {
	int x, h;
};

struct Mons {
	Mon arr[100005];
	int n;
	Mons() : n(0) {}
	void add(Mon m) {
		arr[n++] = m;
	}
	bool operator<(const Mons &b) const {
		return arr[0].x < b.arr[0].x;
	}
};

struct Node {
	int x, h;
};

struct Queue {
	Node arr[100005];
	int n;
	Queue() : n(0) {}
	void push(Node v) {
		arr[n++] = v;
	}
	Node first() {
		return arr[0];
	}
	Node pop() {
		Node res = arr[0];
		for (int i = 1; i < n; i++) {
			arr[i - 1] = arr[i];
		}
		n--;
		return res;
	}
	bool isEmpty() {
		return n == 0;
	}
};

// Queue struct to manage a queue of nodes.
// Methods include pushing, popping, and checking if the queue is empty.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, D, A;
	cin >> N >> D >> A;
	Mons M;
	for (int i = 0; i < N; i++) {
		int x, h;
		cin >> x >> h;
		M.add({x, h});
	}
	sort(M.arr, M.arr + N);
	Queue q;
	int ans = 0, total = 0;
	for (int i = 0; i < N; i++) {
		Mon m = M.arr[i];
		while (!q.isEmpty() && q.first().x < m.x) {
			total -= q.pop().h;
		}
		if (total < m.h) {
			m.h -= total;
			int count = ceil(m.h, A);
			ans += count;
			int damage = count * A;
			q.push({m.x + 2 * D, damage});
			total += damage;
		}
	}
	cout << ans << "\n";
	return 0;
}

