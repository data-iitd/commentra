
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a deque structure with two vectors to represent the front and back.
struct deque {
	vector<char> front, back;
};

// Check if the front of the deque is empty.
bool isEmptyFront(deque &deq) {
	return deq.front.empty();
}

// Check if the back of the deque is empty.
bool isEmptyBack(deque &deq) {
	return deq.back.empty();
}

// Push a character to the back of the deque.
void pushBack(deque &deq, char v) {
	deq.back.push_back(v);
}

// Push a character to the front of the deque.
void pushFront(deque &deq, char v) {
	deq.front.push_back(v);
}

// Pop a character from the back of the deque, or from the front if the back is empty.
bool popBack(deque &deq, char *v) {
	bool r = true;
	if (!isEmptyBack(deq)) {
		*v = deq.back.back();
		deq.back.pop_back();
	} else if (!isEmptyFront(deq)) {
		*v = deq.front.back();
		deq.front.pop_back();
	} else {
		r = false; // Return false if both front and back are empty.
	}
	return r;
}

// Pop a character from the front of the deque, or from the back if the front is empty.
bool popFront(deque &deq, char *v) {
	bool r = true;
	if (!isEmptyFront(deq)) {
		*v = deq.front.back();
		deq.front.pop_back();
	} else if (!isEmptyBack(deq)) {
		*v = deq.back.back();
		deq.back.pop_back();
	} else {
		r = false; // Return false if both front and back are empty.
	}
	return r;
}

// Get a character at a specific index in the deque.
char get(deque &deq, int idx) {
	int tot = deq.front.size() + deq.back.size();
	char v = 0;
	if (idx < tot) {
		if (idx < deq.front.size()) {
			v = deq.front[deq.front.size() - 1 - idx]; // Access from the front.
		} else {
			v = deq.back[idx - deq.front.size()]; // Access from the back.
		}
	}
	return v;
}

// Define an operation structure to hold the operation type and character.
struct op {
	bool rev, front;
	char c;
};

// Reverse a string and return the reversed version.
string rev(string s) {
	string r;
	for (int i = s.size() - 1; i >= 0; i--) {
		r += s[i];
	}
	return r;
}

// Main function to execute the program logic.
int main() {
	string S;
	cin >> S; // Read the initial string S.
	int Q;
	cin >> Q; // Read the number of operations Q.
	vector<op> ops(Q); // Create a vector to hold operations.

	// Read each operation and populate the ops vector.
	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		if (q == 1) {
			ops[i].rev = true; // Mark operation as reverse.
		} else {
			int f;
			cin >> f >> ops[i].c; // Read front/back flag and character.
			if (f == 1) {
				ops[i].front = true; // Mark operation as front insertion.
			}
		}
	}

	// Prepare a sum array to track the number of reversals.
	vector<int> sum(Q + 1);
	for (int i = Q - 1; i >= 1; i--) {
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1; // Increment count if operation is reverse.
		} else {
			sum[i - 1] = sum[i]; // Carry forward the count if not reverse.
		}
	}

	// Reverse the string S if the total number of reversals is odd.
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}

	deque deq; // Initialize a deque to manage character insertions.
	for (int i = 0; i < Q; i++) {
		if (!ops[i].rev) { // Process only non-reverse operations.
			if (ops[i].front) {
				if (sum[i] % 2 == 1) {
					pushBack(deq, ops[i].c); // Push to back if the reversal count is odd.
				} else {
					pushFront(deq, ops[i].c); // Push to front if the reversal count is even.
				}
			} else {
				if (sum[i] % 2 == 1) {
					pushFront(deq, ops[i].c); // Push to front if the reversal count is odd.
				} else {
					pushBack(deq, ops[i].c); // Push to back if the reversal count is even.
				}
			}
		}
	}

	// Prepare to write the final result to standard output.
	for (int i = deq.front.size() - 1; i >= 0; i--) {
		cout << deq.front[i]; // Print front characters in reverse order.
	}
	cout << S; // Print the original string S.
	for (int i = 0; i < deq.back.size(); i++) {
		cout << deq.back[i]; // Print back characters in order.
	}
	cout << endl; // Print a newline at the end.

	return 0;
}

