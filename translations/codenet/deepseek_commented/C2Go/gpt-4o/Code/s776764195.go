package main

import (
	"fmt"
	"os"
)

const (
	MAX_N   = 2000001
	MAX_Ai  = 10001
	STR_SIZE = 10000010
)

var (
	A [MAX_N]int // Input array
	B [MAX_N]int // Output array
	str [STR_SIZE]byte // Buffer to read input
)

func getNum(p *[]byte) int {
	n := 0
	for (*p)[0] >= '0' && (*p)[0] <= '9' {
		n = n*10 + int((*p)[0]-'0') // Convert character to integer
		*p = (*p)[1:] // Move to the next byte
	}
	*p = (*p)[1:] // Move past the space or newline
	return n
}

func putNum(n int, p *[]byte) {
	if n < 10 {
		*p = append(*p, byte('0'+n)) // Write single digit number
		return
	}
	d := n / 10
	if d > 0 {
		putNum(d, p) // Recursively write higher digits
	}
	*p = append(*p, byte('0'+(n-(d*10)))) // Write the last digit
}

func CountingSort(A []int, B []int, k int, len int) {
	C := make([]int, MAX_Ai) // Initialize count array
	for j := 1; j <= len; j++ {
		C[A[j]]++ // Count occurrences of each element
	}
	for i := 1; i <= k; i++ {
		C[i] += C[i-1] // Calculate cumulative count
	}
	for j := len; j > 0; j-- {
		B[C[A[j]]] = A[j] // Place elements in sorted order
		C[A[j]]-- // Decrement count for the element
	}
}

func main() {
	var n int
	var p = str[:]

	// Read input into the buffer
	_, err := os.Stdin.Read(str[:])
	if err != nil {
		fmt.Println("Error reading input:", err)
		return
	}

	n = getNum(&p) // Get the number of elements
	for i := 1; i <= n; i++ {
		A[i] = getNum(&p) // Read each element into the array A
	}

	CountingSort(A[:], B[:], MAX_Ai, n) // Sort the array A using Counting Sort

	p = str[:0] // Reset the pointer to the start of the buffer
	for i := 1; i < n; i++ {
		putNum(B[i], &p) // Write each sorted element
		p = append(p, ' ') // Write a space between elements
	}
	putNum(B[n], &p) // Write the last element without a space

	fmt.Println(string(p)) // Output the sorted string
}

// <END-OF-CODE>
