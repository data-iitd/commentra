// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

// Define a deque (double ended queue) type
class deque {
	// Front and back slices to store the elements
	private byte[] front, back;

	// Function to check if deque is empty at the front
	public boolean isEmptyFront() {
		// Return true if the length of front slice is zero
		return front.length == 0;
	}

	// Function to check if deque is empty at the back
	public boolean isEmptyBack() {
		// Return true if the length of back slice is zero
		return back.length == 0;
	}

	// Function to add an element at the back of the deque
	public void pushBack(byte v) {
		// Append the given byte to the back slice
		back = Arrays.copyOf(back, back.length + 1);
		back[back.length - 1] = v;
	}

	// Function to add an element at the front of the deque
	public void pushFront(byte v) {
		// Append the given byte to the front slice
		front = Arrays.copyOf(front, front.length + 1);
		front[front.length - 1] = v;
	}

	// Function to remove an element from the back of the deque and return it
	public boolean popBack(byte[] v) {
		// If the deque is not empty at the back, pop the last element and return true
		boolean r = true;
		if (!isEmptyBack()) {
			v[0] = back[back.length - 1];
			back = Arrays.copyOf(back, back.length - 1);
		} else if (!isEmptyFront()) { // If the deque is empty at the back but not at the front
			v[0] = front[0];          // Pop the first element
			front = Arrays.copyOf(front, front.length - 1);
		} else {                       // If the deque is empty at both front and back
			r = false;                 // Return false
		}
		return r;
	}

	// Function to remove an element from the front of the deque and return it
	public boolean popFront(byte[] v) {
		// If the deque is not empty at the front, pop the first element and return true
		boolean r = true;
		if (!isEmptyFront()) {
			v[0] = front[front.length - 1];
			front = Arrays.copyOf(front, front.length - 1);
		} else if (!isEmptyBack()) { // If the deque is empty at the front but not at the back
			v[0] = back[0];          // Pop the last element
			back = Arrays.copyOf(back, back.length - 1);
		} else {                       // If the deque is empty at both front and back
			r = false;                 // Return false
		}
		return r;
	}

	// Function to get an element from the deque by its index
	public byte get(int idx) {
		// Calculate the total length of the deque
		int tot = front.length + back.length;
		// If the index is valid, return the corresponding element
		byte v = 0;
		if (idx < tot) {
			if (idx < front.length) {
				v = front[front.length - 1 - idx];
			} else {
				v = back[idx - front.length];
			}
		}
		return v;
	}

	// Function to reverse a given string
	public String rev(String s) {
		// Create a byte array with the length of the given string
		byte[] r = new byte[s.length()];
		// Initialize the indices i and j
		int i = s.length() - 1, j = 0;
		// Iterate through the string from the end to the beginning
		for (i = s.length() - 1; i >= 0; i--) {
			// Store the character at index i in the reverse string
			r[j] = s.charAt(i);
			// Increment j
			j++;
		}
		// Return the reversed string
		return new String(r);
	}
}

// Main function to read input and process it
public class Main {
	// Read the input string S from the standard input
	public static String S;
	public static void main(String[] args) {
		// Read the input string S from the standard input
		Scanner sc = new Scanner(System.in);
		S = sc.next();
		// Read the number of operations Q from the standard input
		int Q = sc.nextInt();
		// Initialize an array of operations ops with the given size
		op[] ops = new op[Q];
		// Read the operations one by one and store them in the ops array
		for (int i = 0; i < Q; i++) {
			// Read the type of operation (reverse or not)
			int q = sc.nextInt();
			// If the operation is to reverse the string, set the rev field to true
			if (q == 1) {
				ops[i] = new op(true);
			} else {
				// Else, read the front flag and the character c from the standard input
				int f = sc.nextInt();
				char c = sc.next().charAt(0);
				// Set the front field based on the front flag
				if (f == 1) {
					ops[i] = new op(false, c, true);
				} else {
					ops[i] = new op(false, c, false);
				}
			}
		}
		// Initialize an array of sums sum with the given size
		int[] sum = new int[Q + 1];
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
			S = new deque().rev(S);
		}
		// Initialize an empty deque deq
		deque deq = new deque();
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
		for (int i = deq.front.length - 1; i >= 0; i--) {
			wtr.write(deq.front[i]);
		}
		// Write the input string to the standard output
		wtr.write(S);
		// Write the characters in the deque to the standard output
		for (int i = 0; i < deq.back.length; i++) {
			wtr.write(deq.back[i]);
		}
		// Flush the buffer and exit
		wtr.flush();
		wtr.close();
	}
}

// Define an operation type
class op {
	// rev field to indicate if the operation is to reverse the string
	public boolean rev;
	// c field to store the character to be added
	public char c;
	// front field to indicate if the character is to be added at the front
	public boolean front;

	// Constructor to initialize the fields
	public op(boolean rev, char c, boolean front) {
		this.rev = rev;
		this.c = c;
		this.front = front;
	}

	// Constructor to initialize the fields
	public op(boolean rev) {
		this.rev = rev;
	}
}

// Define a deque (double ended queue) type
class deque {
	// Front and back slices to store the elements
	private byte[] front, back;

	// Constructor to initialize the fields
	public deque() {
		front = new byte[0];
		back = new byte[0];
	}

	// Function to check if deque is empty at the front
	public boolean isEmptyFront() {
		// Return true if the length of front slice is zero
		return front.length == 0;
	}

	// Function to check if deque is empty at the back
	public boolean isEmptyBack() {
		// Return true if the length of back slice is zero
		return back.length == 0;
	}

	// Function to add an element at the back of the deque
	public void pushBack(byte v) {
		// Append the given byte to the back slice
		back = Arrays.copyOf(back, back.length + 1);
		back[back.length - 1] = v;
	}

	// Function to add an element at the front of the deque
	public void pushFront(byte v) {
		// Append the given byte to the front slice
		front = Arrays.copyOf(front, front.length + 1);
		front[front.length - 1] = v;
	}

	// Function to remove an element from the back of the deque and return it
	public boolean popBack(byte[] v) {
		// If the deque is not empty at the back, pop the last element and return true
		boolean r = true;
		if (!isEmptyBack()) {
			v[0] = back[back.length - 1];
			back = Arrays.copyOf(back, back.length - 1);
		} else if (!isEmptyFront()) { // If the deque is empty at the back but not at the front
			v[0] = front[0];          // Pop the first element
			front = Arrays.copyOf(front, front.length - 1);
		} else {                       // If the deque is empty at both front and back
			r = false;                 // Return false
		}
		return r;
	}

	// Function to remove an element from the front of the deque and return it
	public boolean popFront(byte[] v) {
		// If the deque is not empty at the front, pop the first element and return true
		boolean r = true;
		if (!isEmptyFront()) {
			v[0] = front[front.length - 1];
			front = Arrays.copyOf(front, front.length - 1);
		} else if (!isEmptyBack()) { // If the deque is empty at the front but not at the back
			v[0] = back[0];          // Pop the last element
			back = Arrays.copyOf(back, back.length - 1);
		} else {                       // If the deque is empty at both front and back
			r = false;                 // Return false
		}
		return r;
	}

	// Function to get an element from the deque by its index
	public byte get(int idx) {
		// Calculate the total length of the deque
		int tot = front.length + back.length;
		// If the index is valid, return the corresponding element
		byte v = 0;
		if (idx < tot) {
			if (idx < front.length) {
				v = front[front.length - 1 - idx];
			} else {
				v = back[idx - front.length];
			}
		}
		return v;
	}

	// Function to reverse a given string
	public String rev(String s) {
		// Create a byte array with the length of the given string
		byte[] r = new byte[s.length()];
		// Initialize the indices i and j
		int i = s.length() - 1, j = 0;
		// Iterate through the string from the end to the beginning
		for (i = s.length() - 1; i >= 0; i--) {
			// Store the character at index i in the reverse string
			r[j] 