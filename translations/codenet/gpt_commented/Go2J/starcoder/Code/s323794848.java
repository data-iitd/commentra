package main;

import java.io.*;
import java.util.*;

// Define a deque structure with two slices to represent the front and back.
class deque {
	byte[] front, back;

	// Check if the front of the deque is empty.
	boolean isEmptyFront() {
		return front.length == 0;
	}

	// Check if the back of the deque is empty.
	boolean isEmptyBack() {
		return back.length == 0;
	}

	// Push a byte to the back of the deque.
	void pushBack(byte v) {
		back = Arrays.copyOf(back, back.length+1);
		back[back.length-1] = v;
	}

	// Push a byte to the front of the deque.
	void pushFront(byte v) {
		front = Arrays.copyOf(front, front.length+1);
		front[front.length-1] = v;
	}

	// Pop a byte from the back of the deque, or from the front if the back is empty.
	boolean popBack(byte[] v) {
		boolean r = true;
		if (!isEmptyBack()) {
			v[0] = back[back.length-1];
			back = Arrays.copyOf(back, back.length-1);
		} else if (!isEmptyFront()) {
			v[0] = front[0];
			front = Arrays.copyOfRange(front, 1, front.length);
		} else {
			r = false; // Return false if both front and back are empty.
		}
		return r;
	}

	// Pop a byte from the front of the deque, or from the back if the front is empty.
	boolean popFront(byte[] v) {
		boolean r = true;
		if (!isEmptyFront()) {
			v[0] = front[front.length-1];
			front = Arrays.copyOf(front, front.length-1);
		} else if (!isEmptyBack()) {
			v[0] = back[0];
			back = Arrays.copyOfRange(back, 1, back.length);
		} else {
			r = false; // Return false if both front and back are empty.
		}
		return r;
	}

	// Get a byte at a specific index in the deque.
	byte get(int idx) {
		int tot = front.length + back.length;
		byte v = 0;
		if (idx < tot) {
			if (idx < front.length) {
				v = front[front.length-1-idx]; // Access from the front.
			} else {
				v = back[idx-front.length]; // Access from the back.
			}
		}
		return v;
	}
}

// Define an operation structure to hold the operation type and character.
class op {
	boolean rev, front;
	byte c;
}

// Reverse a string and return the reversed version.
String rev(String s) {
	char[] r = new char[s.length()];
	int i = s.length()-1, j = 0;
	for (i >= 0) {
		r[j] = s.charAt(i);
		j++;
		i--;
	}
	return new String(r);
}

// Main function to execute the program logic.
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String S = br.readLine(); // Read the initial string S.
		int Q = Integer.parseInt(br.readLine()); // Read the number of operations Q.
		op[] ops = new op[Q]; // Create a slice to hold operations.

		// Read each operation and populate the ops slice.
		for (int i = 0; i < Q; i++) {
			int q = Integer.parseInt(br.readLine());
			if (q == 1) {
				ops[i] = new op();
				ops[i].rev = true; // Mark operation as reverse.
			} else {
				int f = Integer.parseInt(br.readLine());
				char c = br.readLine().charAt(0); // Read front/back flag and character.
				if (f == 1) {
					ops[i] = new op();
					ops[i].front = true; // Mark operation as front insertion.
				}
				ops[i].c = (byte) c;
			}
		}

		// Prepare a sum array to track the number of reversals.
		int[] sum = new int[Q+1];
		for (int i = Q - 1; i >= 1; i--) {
			if (ops[i].rev) {
				sum[i-1] = sum[i] + 1; // Increment count if operation is reverse.
			} else {
				sum[i-1] = sum[i]; // Carry forward the count if not reverse.
			}
		}

		// Reverse the string S if the total number of reversals is odd.
		if (sum[0]%2 == 1) {
			S = rev(S);
		}

		deque deq = new deque(); // Initialize a deque to manage character insertions.
		for (int i = 0; i < Q; i++) {
			if (!ops[i].rev) { // Process only non-reverse operations.
				if (ops[i].front) {
					if (sum[i]%2 == 1) {
						deq.pushBack(ops[i].c); // Push to back if the reversal count is odd.
					} else {
						deq.pushFront(ops[i].c); // Push to front if the reversal count is even.
					}
				} else {
					if (sum[i]%2 == 1) {
						deq.pushFront(ops[i].c); // Push to front if the reversal count is odd.
					} else {
						deq.pushBack(ops[i].c); // Push to back if the reversal count is even.
					}
				}
			}
		}

		// Prepare to write the final result to standard output.
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		// Output the characters in the correct order.
		for (int i = deq.front.length-1; i >= 0; i--) {
			wtr.write(deq.front[i]); // Print front characters in reverse order.
		}
		for (int i = 0; i < S.length(); i++) {
			wtr.write(S.charAt(i)); // Print the original string S.
		}
		for (int i = 0; i < deq.back.length; i++) {
			wtr.write(deq.back[i]); // Print back characters in order.
		}
		wtr.write('\n'); // Print a newline at the end.
		wtr.flush(); // Flush the buffered writer to ensure all output is written.
	}
}

