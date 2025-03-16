package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Define constants for maximum sizes
const (
	MAX_N    = 2000001
	MAX_Ai   = 10001
	STR_SIZE = 10000010
)

// Global arrays for input and output
var A [MAX_N]int
var B [MAX_N]int
var str [STR_SIZE]byte
var p = str[:0]

func main() {
	reader := bufio.NewReader(os.Stdin)
	
	// Read the entire input into the string
	input, _ := reader.ReadBytes('\n')
	
	// Get the number of elements from the input
	n, _ := strconv.Atoi(string(input[:len(input)-1]))
	
	// Read each number into the array A
	for i := 1; i <= n; i++ {
		A[i], _ = strconv.Atoi(string(input[i:]))
		i++
	}
	
	// Perform counting sort on the array A and store the result in B
	CountingSort(A[:n+1], B[:n+1], MAX_Ai, n)
	
	// Write the sorted numbers to the output string
	for i := 1; i <= n; i++ {
		putNum(B[i])
		if i < n {
			p = append(p, ' ')
		}
	}
	p = append(p, '\000')
	
	// Output the final result
	fmt.Println(string(str[:]))
}

// Function to write an integer to the output string
func putNum(n int) {
	if n < 10 {
		p = append(p, byte('0'+n))
		return
	}
	
	// Recursively write the digits of the number
	d := n / 10
	if d > 0 {
		putNum(d)
	}
	p = append(p, byte('0'+(n-(d*10))))
}

// Counting sort algorithm implementation
func CountingSort(A, B []int, k, len int) {
	C := make([]int, k+1)
	
	// Count occurrences of each number in A
	for _, j := range A {
		C[j]++
	}
	
	// Update count array to hold the position of each number
	for i := 1; i <= k; i++ {
		C[i] += C[i-1]
	}
	
	// Build the output array B using the count array
	for j := len; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

