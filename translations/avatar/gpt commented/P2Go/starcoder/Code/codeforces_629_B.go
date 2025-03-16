package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Use bufio for faster input reading
var reader = bufio.NewReader(os.Stdin)

// Initialize a constant N for the size of the arrays
const N = 368

// Create two lists to track the values for 'M' and 'F'
var m = make([]int, N)  // List to track 'M' values
var f = make([]int, N)  // List to track 'F' values

// Read the number of operations from input
func main() {
	var n int
	fmt.Fscanln(reader, &n)

	// Read the operations from input
	for i := 0; i < n; i++ {
		// Read the operation type and the indices a and b
		var x string
		var a, b int
		fmt.Fscanln(reader, &x, &a, &b)

		// Update the corresponding list based on the operation type
		if x == "M" {
			m[a] += 2  // Increment the value at index a in the 'M' list
			m[b] -= 2  // Decrement the value at index b in the 'M' list
		} else {
			f[a] += 2  // Increment the value at index a in the 'F' list
			f[b] -= 2  // Decrement the value at index b in the 'F' list
	}

	// Initialize variables to track cumulative sums and the minimum value
	var a, b, c int

	// Iterate through the range of N to calculate cumulative sums and find the minimum
	for i := 0; i < N; i++ {
		a += m[i]  // Update cumulative sum for 'M'
		b += f[i]  // Update cumulative sum for 'F'

		// Update the minimum value if the current minimum of a and b is greater than c
		if min(a, b) > c {
			c = min(a, b)  // Set c to the new minimum value
	}

	// Print the final minimum value found
	fmt.Println(c)
}

// Return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE

# Python:
import sys

# Use readline for faster input reading
input = sys.stdin.readline

# Initialize a constant N for the size of the arrays
N = 368

# Create two lists to track the values for 'M' and 'F'
m = [0] * N  # List to track 'M' values
f = [0] * N  # List to track 'F' values

# Read the number of operations from input
for i in range(int(input())):
    # Read the operation type and the indices a and b
    x, a, b = input()[:-1].split()  # Remove the trailing newline
    a = int(a)  # Convert a to an integer
    b = int(b) + 1  # Convert b to an integer and increment by 1 for range adjustment

    # Update the corresponding list based on the operation type
    if x == 'M':
        m[a] += 2  # Increment the value at index a in the 'M' list
        m[b] -= 2  # Decrement the value at index b in the 'M' list
    else:
        f[a] += 2  # Increment the value at index a in the 'F' list
        f[b] -= 2  # Decrement the value at index b in the 'F' list

# Initialize variables to track cumulative sums and the minimum value
a, b, c = 0, 0, 0

# Iterate through the range of N to calculate cumulative sums and find the minimum
for i in range(N):
    a += m[i]  # Update cumulative sum for 'M'
    b += f[i]  # Update cumulative sum for 'F'
    
    # Update the minimum value if the current minimum of a and b is greater than c
    if min(a, b) > c:
        c = min(a, b)  # Set c to the new minimum value

# Print the final minimum value found
print(c)


Translate the above Python code to Go and end with comment "