
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Use bufio for faster input reading
	reader := bufio.NewReader(os.Stdin)

	// Initialize a constant N for the size of the arrays
	const N = 368

	// Create two slices to track the values for 'M' and 'F'
	m := make([]int, N)  // Slice to track 'M' values
	f := make([]int, N)  // Slice to track 'F' values

	// Read the number of operations from input
	for i := 0; i < int(readNum(reader)); i++ {
		// Read the operation type and the indices a and b
		x, a, b := readWords(reader)  // Read the operation type and the indices a and b
		a = int(a[0]) - 1  // Convert a to an integer and subtract 1 for 0-based indexing
		b = int(b[0])  // Convert b to an integer

		// Update the corresponding slice based on the operation type
		if x[0] == 'M' {
			m[a] += 2  // Increment the value at index a in the 'M' slice
			m[b] -= 2  // Decrement the value at index b in the 'M' slice
		} else {
			f[a] += 2  // Increment the value at index a in the 'F' slice
			f[b] -= 2  // Decrement the value at index b in the 'F' slice
		}
	}

	// Initialize variables to track cumulative sums and the minimum value
	a, b, c := 0, 0, 0

	// Iterate through the range of N to calculate cumulative sums and find the minimum
	for i := 0; i < N; i++ {
		a += m[i]  // Update cumulative sum for 'M'
		b += f[i]  // Update cumulative sum for 'F'

		// Update the minimum value if the current minimum of a and b is greater than c
		if min(a, b) > c {
			c = min(a, b)  // Set c to the new minimum value
		}
	}

	// Print the final minimum value found
	fmt.Println(c)
}

func readNum(reader *bufio.Reader) []byte {
	res := []byte{}
	c := byte(0)
	for c < '0' || c > '9' {
		c, _ = reader.ReadByte()
	}
	for c >= '0' && c <= '9' {
		res = append(res, c)
		c, _ = reader.ReadByte()
	}
	return res
}

func readWord(reader *bufio.Reader) []byte {
	res := []byte{}
	c := byte(0)
	for c < 'a' || c > 'z' {
		c, _ = reader.ReadByte()
	}
	for c >= 'a' && c <= 'z' {
		res = append(res, c)
		c, _ = reader.ReadByte()
	}
	return res
}

func readWords(reader *bufio.Reader) ([]byte, []byte, []byte) {
	res1 := readWord(reader)
	res2 := readNum(reader)
	res3 := readNum(reader)
	reader.ReadByte()  // Consume the trailing newline
	return res1, res2, res3
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

