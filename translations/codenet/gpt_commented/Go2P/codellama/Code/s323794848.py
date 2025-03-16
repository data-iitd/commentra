
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Define a deque structure with two slices to represent the front and back.
type deque struct {
	front, back []byte
}

// Check if the front of the deque is empty.
func (deq *deque) isEmptyFront() bool {
	return len(deq.front) == 0
}

// Check if the back of the deque is empty.
func (deq *deque) isEmptyBack() bool {
	return len(deq.back) == 0
}

// Push a byte to the back of the deque.
func (deq *deque) pushBack(v byte) {
	deq.back = append(deq.back, v)
}

// Push a byte to the front of the deque.
func (deq *deque) pushFront(v byte) {
	deq.front = append(deq.front, v)
}

// Pop a byte from the back of the deque, or from the front if the back is empty.
func (deq *deque) popBack(v *byte) bool {
	r := true
	if !deq.isEmptyBack() {
		*v = deq.back[len(deq.back)-1]
		deq.back = deq.back[:len(deq.back)-1]
	} else if !deq.isEmptyFront() {
		*v = deq.front[0]
		deq.front = deq.front[1:]
	} else {
		r = false // Return false if both front and back are empty.
	}
	return r
}

// Pop a byte from the front of the deque, or from the back if the front is empty.
func (deq *deque) popFront(v *byte) bool {
	r := true
	if !deq.isEmptyFront() {
		*v = deq.front[len(deq.front)-1]
		deq.front = deq.front[:len(deq.front)-1]
	} else if !deq.isEmptyBack() {
		*v = deq.back[0]
		deq.back = deq.back[1:]
	} else {
		r = false // Return false if both front and back are empty.
	}
	return r
}

// Get a byte at a specific index in the deque.
func (deq *deque) get(idx int) byte {
	tot := len(deq.front) + len(deq.back)
	var v byte
	if idx < tot {
		if idx < len(deq.front) {
			v = deq.front[len(deq.front)-1-idx] // Access from the front.
		} else {
			v = deq.back[idx-len(deq.front)] // Access from the back.
		}
	}
	return v
}

// Define an operation structure to hold the operation type and character.
type op struct {
	rev, front bool
	c          byte
}

// Reverse a string and return the reversed version.
func rev(s string) string {
	r := make([]byte, len(s))
	i, j := len(s)-1, 0
	for i >= 0 {
		r[j] = s[i]
		j++
		i--
	}
	return string(r)
}

// Main function to execute the program logic.
func main() {
	var S string
	fmt.Scan(&S) // Read the initial string S.
	var Q int
	fmt.Scan(&Q) // Read the number of operations Q.
	ops := make([]op, Q) // Create a slice to hold operations.

	// Read each operation and populate the ops slice.
	for i := 0; i < Q; i++ {
		var q int
		fmt.Scan(&q)
		if q == 1 {
			ops[i].rev = true // Mark operation as reverse.
		} else {
			var f int
			fmt.Scanf("%d %c", &f, &ops[i].c) // Read front/back flag and character.
			if f == 1 {
				ops[i].front = true // Mark operation as front insertion.
			}
		}
	}

	// Prepare a sum array to track the number of reversals.
	sum := make([]int, Q+1)
	for i := Q - 1; i >= 1; i-- {
		if ops[i].rev {
			sum[i-1] = sum[i] + 1 // Increment count if operation is reverse.
		} else {
			sum[i-1] = sum[i] // Carry forward the count if not reverse.
		}
	}

	// Reverse the string S if the total number of reversals is odd.
	if sum[0]%2 == 1 {
		S = rev(S)
	}

	var deq deque // Initialize a deque to manage character insertions.
	for i := 0; i < Q; i++ {
		if !ops[i].rev { // Process only non-reverse operations.
			if ops[i].front {
				if sum[i]%2 == 1 {
					deq.pushBack(ops[i].c) // Push to back if the reversal count is odd.
				} else {
					deq.pushFront(ops[i].c) // Push to front if the reversal count is even.
				}
			} else {
				if sum[i]%2 == 1 {
					deq.pushFront(ops[i].c) // Push to front if the reversal count is odd.
				} else {
					deq.pushBack(ops[i].c) // Push to back if the reversal count is even.
				}
			}
		}
	}

	// Prepare to write the final result to standard output.
	wtr := bufio.NewWriter(os.Stdout)
	// Output the characters in the correct order.
	for i := len(deq.front) - 1; i >= 0; i-- {
		fmt.Fprint(wtr, string(deq.front[i])) // Print front characters in reverse order.
	}
	for i := 0; i < len(S); i++ {
		fmt.Fprint(wtr, string(S[i])) // Print the original string S.
	}
	for i := 0; i < len(deq.back); i++ {
		fmt.Fprint(wtr, string(deq.back[i])) // Print back characters in order.
	}
	fmt.Fprintln(wtr) // Print a newline at the end.
	wtr.Flush() // Flush the buffered writer to ensure all output is written.
}


