
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Deque structure to simulate a double-ended queue
struct deque {
	vector<char> front, back;
};

// Check if the front of the deque is empty
bool isEmptyFront(deque &deq) {
	return deq.front.empty();
}

// Check if the back of the deque is empty
bool isEmptyBack(deque &deq) {
	return deq.back.empty();
}

// Push a byte to the back of the deque
void pushBack(deque &deq, char v) {
	deq.back.push_back(v);
}

// Push a byte to the front of the deque
void pushFront(deque &deq, char v) {
	deq.front.push_back(v);
}

// Pop a byte from the back of the deque
bool popBack(deque &deq, char *v) {
	bool r = true;
	if (!isEmptyBack(deq)) {
		*v = deq.back.back();
		deq.back.pop_back();
	} else if (!isEmptyFront(deq)) {
		*v = deq.front.back();
		deq.front.pop_back();
	} else {
		r = false;
	}
	return r;
}

// Pop a byte from the front of the deque
bool popFront(deque &deq, char *v) {
	bool r = true;
	if (!isEmptyFront(deq)) {
		*v = deq.front.back();
		deq.front.pop_back();
	} else if (!isEmptyBack(deq)) {
		*v = deq.back.back();
		deq.back.pop_back();
	} else {
		r = false;
	}
	return r;
}

// Get the byte at a specific index in the deque
char get(deque &deq, int idx) {
	int tot = deq.front.size() + deq.back.size();
	char v = 0;
	if (idx < tot) {
		if (idx < deq.front.size()) {
			v = deq.front[deq.front.size() - 1 - idx];
		} else {
			v = deq.back[idx - deq.front.size()];
		}
	}
	return v;
}

// Operation struct to store each operation's details
struct op {
	bool rev, front;
	char c;
};

// Reverse a string
string rev(string s) {
	string r;
	for (int i = s.size() - 1; i >= 0; i--) {
		r += s[i];
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
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	deque deq;
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // Not a reversal operation (string append)
			if (ops[i].front) {
				if (sum[i] % 2 == 1) {
					pushBack(deq, ops[i].c);
				} else {
					pushFront(deq, ops[i].c);
				}
			} else {
				if (sum[i] % 2 == 1) {
					pushFront(deq, ops[i].c);
				} else {
					pushBack(deq, ops[i].c);
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

