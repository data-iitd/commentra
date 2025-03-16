// Package main is the entry point of the program
package main

import (
	"bufio"  // For I/O operations
	"fmt"    // For formatted I/O
	"os"     // For I/O operations
)

// Define a deque (double ended queue) type
type deque struct {
	front, back []byte // Front and back slices to store the elements
}

// Function to check if deque is empty at the front
func (deq *deque) isEmptyFront() bool {
	// Return true if the length of front slice is zero
	return len(deq.front) == 0
}

// Function to check if deque is empty at the back
func (deq *deque) isEmptyBack() bool {
	// Return true if the length of back slice is zero
	return len(deq.back) == 0
}

// Function to add an element at the back of the deque
func (deq *deque) pushBack(v byte) {
	// Append the given byte to the back slice
	deq.back = append(deq.back, v)
}

// Function to add an element at the front of the deque
func (deq *deque) pushFront(v byte) {
	// Append the given byte to the front slice
	deq.front = append(deq.front, v)
}

// Function to remove an element from the back of the deque and return it
func (deq *deque) popBack(v *byte) bool {
	// If the deque is not empty at the back, pop the last element and return true
	r := true
	if !deq.isEmptyBack() {
		*v = deq.back[len(deq.back)-1]
		deq.back = deq.back[:len(deq.back)-1]
	} else if !deq.isEmptyFront() { // If the deque is empty at the back but not at the front
		*v = deq.front[0]          // Pop the first element
		deq.front = deq.front[1:]   // Update the front slice
	} else {                       // If the deque is empty at both front and back
		r = false                  // Return false
	}
	return r
}

// Function to remove an element from the front of the deque and return it
func (deq *deque) popFront(v *byte) bool {
	// If the deque is not empty at the front, pop the first element and return true
	r := true
	if !deq.isEmptyFront() {
		*v = deq.front[len(deq.front)-1]
		deq.front = deq.front[:len(deq.front)-1]
	} else if !deq.isEmptyBack() { // If the deque is empty at the front but not at the back
		*v = deq.back[0]          // Pop the last element
		deq.back = deq.back[1:]   // Update the back slice
	} else {                       // If the deque is empty at both front and back
		r = false                  // Return false
	}
	return r
}

// Function to get an element from the deque by its index
func (deq *deque) get(idx int) byte {
	// Calculate the total length of the deque
	tot := len(deq.front) + len(deq.back)
	// If the index is valid, return the corresponding element
	var v byte
	if idx < tot {
		if idx < len(deq.front) {
			v = deq.front[len(deq.front)-1-idx]
		} else {
			v = deq.back[idx-len(deq.front)]
		}
	}
	return v
}

// Function to reverse a given string
func rev(s string) string {
	// Create a byte slice with the length of the given string
	r := make([]byte, len(s))
	// Initialize the indices i and j
	i, j := len(s)-1, 0
	// Iterate through the string from the end to the beginning
	for i >= 0 {
		// Store the character at index i in the reverse string
		r[j] = s[i]
		// Increment j
		j++
		// Decrement i
		i--
	}
	// Return the reversed string
	return string(r)
}

// Main function to read input and process it
func main() {
	// Read the input string S from the standard input
	var S string
	fmt.Scan(&S)
	// Read the number of operations Q from the standard input
	var Q int
	fmt.Scan(&Q)
	// Initialize an array of operations ops with the given size
	ops := make([]op, Q)
	// Read the operations one by one and store them in the ops array
	for i := 0; i < Q; i++ {
		// Read the type of operation (reverse or not)
		var q int
		fmt.Scan(&q)
		// If the operation is to reverse the string, set the rev field to true
		if q == 1 {
			ops[i].rev = true
		} else {
			// Else, read the front flag and the character c from the standard input
			var f int
			fmt.Scanf("%d %c", &f, &ops[i].c)
			// Set the front field based on the front flag
			if f == 1 {
				ops[i].front = true
			}
		}
	}
	// Initialize an array of sums sum with the given size
	sum := make([]int, Q+1)
	// Initialize the sum of the first operation
	sum[0] = 0
	// Iterate through the remaining operations and calculate their sums
	for i := Q - 1; i >= 0; i-- {
		// If the current operation is to reverse the string, increment the previous sum
		if ops[i].rev {
			sum[i-1] = sum[i] + 1
		} else {
			// Else, set the previous sum to the current sum
			sum[i-1] = sum[i]
		}
	}
	// If the sum of the first operation is odd, reverse the input string
	if sum[0]%2 == 1 {
		S = rev(S)
	}
	// Initialize an empty deque deq
	var deq deque
	// Iterate through the operations and process them based on their type
	for i := 0; i < Q; i++ {
		// If the current operation is not to reverse the string
		if !ops[i].rev {
			// If the operation is to add a character at the front, process it accordingly
			if ops[i].front {
				// If the previous sum is odd, push the character to the front of the deque
				if sum[i]%2 == 1 {
					deq.pushFront(ops[i].c)
				} else {
					deq.pushBack(ops[i].c)
				}
			} else { // Else, process the operation to add a character at the end
				// If the previous sum is odd, push the character to the end of the deque
				if sum[i]%2 == 1 {
					deq.pushBack(ops[i].c)
				} else {
					deq.pushFront(ops[i].c)
				}
			}
		}
	}
	// Write the result to the standard output
	wtr := bufio.NewWriter(os.Stdout)
	// Write the characters in the deque to the standard output
	for i := len(deq.front) - 1; i >= 0; i-- {
		fmt.Fprint(wtr, string(deq.front[i]))
	}
	// Write the input string to the standard output
	for i := 0; i < len(S); i++ {
		fmt.Fprint(wtr, string(S[i]))
	}
	// Write the characters in the deque to the standard output
	for i := 0; i < len(deq.back); i++ {
		fmt.Fprint(wtr, string(deq.back[i]))
	}
	// Flush the buffer and exit
	fmt.Fprintln(wtr)
}
