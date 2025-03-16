
#include <bits/stdc++.h>

using namespace std;

// Define a deque (double ended queue) type
struct deque {
	vector<char> front, back; // Front and back vectors to store the elements
};

// Function to check if deque is empty at the front
bool isEmptyFront(deque *deq) {
	// Return true if the length of front vector is zero
	return deq->front.size() == 0;
}

// Function to check if deque is empty at the back
bool isEmptyBack(deque *deq) {
	// Return true if the length of back vector is zero
	return deq->back.size() == 0;
}

// Function to add an element at the back of the deque
void pushBack(deque *deq, char v) {
	// Append the given character to the back vector
	deq->back.push_back(v);
}

// Function to add an element at the front of the deque
void pushFront(deque *deq, char v) {
	// Append the given character to the front vector
	deq->front.push_back(v);
}

// Function to remove an element from the back of the deque and return it
bool popBack(deque *deq, char *v) {
	// If the deque is not empty at the back, pop the last element and return true
	bool r = true;
	if (!isEmptyBack(deq)) {
		*v = deq->back[deq->back.size() - 1];
		deq->back.pop_back();
	} else if (!isEmptyFront(deq)) { // If the deque is empty at the back but not at the front
		*v = deq->front[0];          // Pop the first element
		deq->front.erase(deq->front.begin());   // Update the front vector
	} else {                       // If the deque is empty at both front and back
		r = false;                  // Return false
	}
	return r;
}

// Function to remove an element from the front of the deque and return it
bool popFront(deque *deq, char *v) {
	// If the deque is not empty at the front, pop the first element and return true
	bool r = true;
	if (!isEmptyFront(deq)) {
		*v = deq->front[deq->front.size() - 1];
		deq->front.pop_back();
	} else if (!isEmptyBack(deq)) { // If the deque is empty at the front but not at the back
		*v = deq->back[0];          // Pop the last element
		deq->back.erase(deq->back.begin());   // Update the back vector
	} else {                       // If the deque is empty at both front and back
		r = false;                  // Return false
	}
	return r;
}

// Function to get an element from the deque by its index
char get(deque *deq, int idx) {
	// Calculate the total length of the deque
	int tot = deq->front.size() + deq->back.size();
	// If the index is valid, return the corresponding element
	char v = 0;
	if (idx < tot) {
		if (idx < deq->front.size()) {
			v = deq->front[deq->front.size() - 1 - idx];
		} else {
			v = deq->back[idx - deq->front.size()];
		}
	}
	return v;
}

// Function to reverse a given string
string rev(string s) {
	// Create a string r with the length of the given string
	string r(s.size(), 0);
	// Initialize the indices i and j
	int i = s.size() - 1, j = 0;
	// Iterate through the string from the end to the beginning
	for (i; i >= 0; i--) {
		// Store the character at index i in the reverse string
		r[j] = s[i];
		// Increment j
		j++;
	}
	// Return the reversed string
	return r;
}

// Main function to read input and process it
int main() {
	// Read the input string S from the standard input
	string S;
	cin >> S;
	// Read the number of operations Q from the standard input
	int Q;
	cin >> Q;
	// Initialize an array of operations ops with the given size
	op ops[Q];
	// Read the operations one by one and store them in the ops array
	for (int i = 0; i < Q; i++) {
		// Read the type of operation (reverse or not)
		int q;
		cin >> q;
		// If the operation is to reverse the string, set the rev field to true
		if (q == 1) {
			ops[i].rev = true;
		} else {
			// Else, read the front flag and the character c from the standard input
			int f;
			cin >> f >> ops[i].c;
			// Set the front field based on the front flag
			if (f == 1) {
				ops[i].front = true;
			}
		}
	}
	// Initialize an array of sums sum with the given size
	int sum[Q + 1];
	// Initialize the sum of the first operation
	sum[0] = 0;
	// Iterate through the remaining operations and calculate their sums
	for (int i = Q - 1; i >= 0; i--) {
		// If the current operation is to reverse the string, increment the previous sum
		if (ops[i].rev) {
			sum[i - 1] = sum[i] + 1;
		} else {
			// Else, set the previous sum to the current sum
			sum[i - 1] = sum[i];
		}
	}
	// If the sum of the first operation is odd, reverse the input string
	if (sum[0] % 2 == 1) {
		S = rev(S);
	}
	// Initialize an empty deque deq
	deque deq;
	// Iterate through the operations and process them based on their type
	for (int i = 0; i < Q; i++) {
		// If the current operation is not to reverse the string
		if (!ops[i].rev) {
			// If the operation is to add a character at the front, process it accordingly
			if (ops[i].front) {
				// If the previous sum is odd, push the character to the front of the deque
				if (sum[i] % 2 == 1) {
					pushFront(&deq, ops[i].c);
				} else {
					pushBack(&deq, ops[i].c);
				}
			} else { // Else, process the operation to add a character at the end
				// If the previous sum is odd, push the character to the end of the deque
				if (sum[i] % 2 == 1) {
					pushBack(&deq, ops[i].c);
				} else {
					pushFront(&deq, ops[i].c);
				}
			}
		}
	}
	// Write the result to the standard output
	// Write the characters in the deque to the standard output
	for (int i = deq.front.size() - 1; i >= 0; i--) {
		cout << deq.front[i];
	}
	// Write the input string to the standard output
	cout << S;
	// Write the characters in the deque to the standard output
	for (int i = 0; i < deq.back.size(); i++) {
		cout << deq.back[i];
	}
	// Exit
	return 0;
}

