package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read two integers n and m
	scanner.Scan()
	n := parseInt(scanner.Bytes())
	scanner.Scan()
	m := parseInt(scanner.Bytes())

	// Initialize a slice 'b' of length 2 * n with all elements as 1
	b := make([]int, n*2)
	for i := range b {
		b[i] = 1
	}

	// Set the first, last and middle elements of the slice 'b' to 0
	b[0] = 0
	b[n-1] = 0
	b[n] = 0
	b[2*n-1] = 0

	// Iterate through the given 'm' pairs of row and column indices
	for i := 0; i < m; i++ {
		// Read row and column indices
		scanner.Scan()
		r := parseInt(scanner.Bytes()) - 1
		scanner.Scan()
		c := parseInt(scanner.Bytes()) - 1

		// Set the elements at the given row and column indices to 0 in the slice 'b'
		b[r] = 0
		b[n+c] = 0
	}

	// Check if n is odd and if the middle two elements of the slice 'b' are 1, then set the middle element to 0
	if n%2 == 1 && b[n/2] == 1 && b[n+n/2] == 1 {
		b[n/2] = 0
	}

	// Calculate and print the sum of all elements in the slice 'b'
	sum := 0
	for _, v := range b {
		sum += v
	}
	fmt.Println(sum)
}

// parseInt converts a byte slice to an integer
func parseInt(b []byte) int {
	var num int
	for _, v := range b {
		num = num*10 + int(v-'0')
	}
	return num
}

