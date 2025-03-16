
// Package main is the entry point of the program
package main

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

// Define a deque (double ended queue) type
class Deque {
	// Front and back slices to store the elements
	private List<Character> front = new ArrayList<>();
	private List<Character> back = new ArrayList<>();

	// Function to check if deque is empty at the front
	public boolean isEmptyFront() {
		// Return true if the length of front slice is zero
		return front.size() == 0;
	}

	// Function to check if deque is empty at the back
	public boolean isEmptyBack() {
		// Return true if the length of back slice is zero
		return back.size() == 0;
	}

	// Function to add an element at the back of the deque
	public void pushBack(char v) {
		// Append the given character to the back slice
		back.add(v);
	}

	// Function to add an element at the front of the deque
	public void pushFront(char v) {
		// Append the given character to the front slice
		front.add(v);
	}

	// Function to remove an element from the back of the deque and return it
	public char popBack() {
		// If the deque is not empty at the back, pop the last element and return it
		char v = ' ';
		if (!isEmptyBack()) {
			v = back.get(back.size() - 1);
			back.remove(back.size() - 1);
		} else if (!isEmptyFront()) { // If the deque is empty at the back but not at the front
			v = front.get(0);          // Pop the first element
			front.remove(0);           // Update the front slice
		}
		return v;
	}

	// Function to remove an element from the front of the deque and return it
	public char popFront() {
		// If the deque is not empty at the front, pop the first element and return it
		char v = ' ';
		if (!isEmptyFront()) {
			v = front.get(front.size() - 1);
			front.remove(front.size() - 1);
		} else if (!isEmptyBack()) { // If the deque is empty at the front but not at the back
			v = back.get(0);          // Pop the last element
			back.remove(0);           // Update the back slice
		}
		return v;
	}

	// Function to get an element from the deque by its index
	public char get(int idx) {
		// Calculate the total length of the deque
		int tot = front.size() + back.size();
		// If the index is valid, return the corresponding element
		char v = ' ';
		if (idx < tot) {
			if (idx < front.size()) {
				v = front.get(front.size() - 1 - idx);
			} else {
				v = back.get(idx - front.size());
			}
		}
		return v;
	}

	// Function to reverse a given string
	public static String rev(String s) {
		// Create a char array with the length of the given string
		char[] r = new char[s.length()];
		// Initialize the indices i and j
		int i = s.length() - 1, j = 0;
		// Iterate through the string from the end to the beginning
		while (i >= 0) {
			// Store the character at index i in the reverse string
			r[j] = s.charAt(i);
			// Increment j
			j++;
			// Decrement i
			i--;
		}
		// Return the reversed string
		return new String(r);
	}
}

// Define an operation type
class Op {
	// Flag to indicate if the operation is to reverse the string
	public boolean rev;
	// Flag to indicate if the operation is to add a character at the front
	public boolean front;
	// Character to add
	public char c;
}

// Main function to read input and process it
public class Main {
	public static void main(String[] args) throws Exception {
		// Read the input string S from the standard input
		BufferedReader rdr = new BufferedReader(new InputStreamReader(System.in));
		String S = rdr.readLine();
		// Read the number of operations Q from the standard input
		int Q = Integer.parseInt(rdr.readLine());
		// Initialize an array of operations ops with the given size
		Op[] ops = new Op[Q];
		// Read the operations one by one and store them in the ops array
		for (int i = 0; i < Q; i++) {
			// Read the type of operation (reverse or not)
			int q = Integer.parseInt(rdr.readLine());
			// If the operation is to reverse the string, set the rev field to true
			if (q == 1) {
				ops[i] = new Op();
				ops[i].rev = true;
			} else {
				// Else, read the front flag and the character c from the standard input
				String[] s = rdr.readLine().split(" ");
				int f = Integer.parseInt(s[0]);
				char c = s[1].charAt(0);
				// Set the front field based on the front flag
				if (f == 1) {
					ops[i] = new Op();
					ops[i].front = true;
					ops[i].c = c;
				} else {
					ops[i] = new Op();
					ops[i].c = c;
				}
			}
		}
		// Initialize an array of sums sum with the given size
		int[] sum = new int[Q + 1];
		// Initialize the sum of the first operation
		sum[0] = 0;
		// Iterate through the remaining operations and calculate their sums
		for (int i = Q - 1; i >= 0; i--) {
			// If the current operation is not to reverse the string
			if (!ops[i].rev) {
				// If the operation is to add a character at the front, process it accordingly
				if (ops[i].front) {
					// If the previous sum is odd, push the character to the front of the deque
					if (sum[i] % 2 == 1) {
						sum[i - 1] = sum[i] + 1;
					} else {
						sum[i - 1] = sum[i];
					}
				} else { // Else, process the operation to add a character at the end
					// If the previous sum is odd, push the character to the end of the deque
					if (sum[i] % 2 == 1) {
						sum[i - 1] = sum[i] + 1;
					} else {
						sum[i - 1] = sum[i];
					}
				}
			}
		}
		// If the sum of the first operation is odd, reverse the input string
		if (sum[0] % 2 == 1) {
			S = rev(S);
		}
		// Initialize an empty deque deq
		Deque deq = new Deque();
		// Iterate through the operations and process them based on their type
		for (int i = 0; i < Q; i++) {
			// If the current operation is not to reverse the string
			if (!ops[i].rev) {
				// If the operation is to add a character at the front, process it accordingly
				if (ops[i].front) {
					// If the previous sum is odd, push the character to the front of the deque
					if (sum[i] % 2 == 1) {
						deq.pushFront(ops[i].c);
					} else {
						deq.pushBack(ops[i].c);
					}
				} else { // Else, process the operation to add a character at the end
					// If the previous sum is odd, push the character to the end of the deque
					if (sum[i] % 2 == 1) {
						deq.pushBack(ops[i].c);
					} else {
						deq.pushFront(ops[i].c);
					}
				}
			}
		}
		// Write the result to the standard output
		BufferedWriter wtr = new BufferedWriter(new OutputStreamWriter(System.out));
		// Write the characters in the deque to the standard output
		for (int i = deq.front.size() - 1; i >= 0; i--) {
			wtr.write(deq.front.get(i).toString());
		}
		// Write the input string to the standard output
		wtr.write(S);
		// Write the characters in the deque to the standard output
		for (int i = 0; i < deq.back.size(); i++) {
			wtr.write(deq.back.get(i).toString());
		}
		// Flush the buffer and exit
		wtr.write("\n");
		wtr.flush();
	}
}

