
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct deque {
	vector<char> front, back;

	bool isEmptyFront() {
		return front.empty();
	}
	bool isEmptyBack() {
		return back.empty();
	}

	void pushBack(char v) {
		back.push_back(v);
	}
	void pushFront(char v) {
		front.push_back(v);
	}
	bool popBack(char *v) {
		bool r = true;
		if (!isEmptyBack()) {
			*v = back.back();
			back.pop_back();
		} else if (!isEmptyFront()) {
			*v = front.front();
			front.erase(front.begin());
		} else {
			r = false;
		}
		return r;
	}
	bool popFront(char *v) {
		bool r = true;
		if (!isEmptyFront()) {
			*v = front.back();
			front.pop_back();
		} else if (!isEmptyBack()) {
			*v = back.front();
			back.erase(back.begin());
		} else {
			r = false;
		}
		return r;
	}

	char get(int idx) {
		int tot = front.size() + back.size();
		char v = 0;
		if (idx < tot) {
			if (idx < front.size()) {
				v = front[front.size() - 1 - idx];
			} else {
				v = back[idx - front.size()];
			}
		}
		return v;
	}
};

struct op {
	bool rev, front;
	char c;
};

string rev(string s) {
	string r;
	r.resize(s.size());
	int i = s.size() - 1, j = 0;
	while (i >= 0) {
		r[j] = s[i];
		j++;
		i--;
	}
	return r;
}

int main() {
	string S;
	cin >> S;
	int Q;
	cin >> Q;
	vector<op> ops(Q);
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		if (q == 1) {
			ops[i].rev = true;
		} else {
			int f;
			cin >> f >> ops[i].c;
			if (f == 1) {
				ops[i].front = true;
			}
		}
	}
	vector<int> sum(Q + 1);
	for (int i = Q - 1; i >= 1; i--) {
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1;
		} else {
			sum[i - 1] = sum[i];
		}
	}
	// cout << "S " << S << " Q " << Q << " ops " << ops << " sum " << sum << endl;
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	deque deq;
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // 反転ではない(文字列追加)
			if (ops[i].front) {
				if (sum[i] % 2 == 1) {
					deq.pushBack(ops[i].c);
				} else {
					deq.pushFront(ops[i].c);
				}
			} else {
				if (sum[i] % 2 == 1) {
					deq.pushFront(ops[i].c);
				} else {
					deq.pushBack(ops[i].c);
				}
			}
		}
	}
	for (int i = deq.front.size() - 1; i >= 0; i--) {
		cout << deq.front[i];
	}
	cout << S;
	for (int i = 0; i < deq.back.size(); i++) {
		cout << deq.back[i];
	}
	cout << endl;
	return 0;
}

