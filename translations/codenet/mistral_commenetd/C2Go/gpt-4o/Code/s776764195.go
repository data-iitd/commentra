package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	MAX_N    = 2000001 // Maximum number of integers to be read
	MAX_Ai   = 10001   // Maximum value of an integer
	STR_SIZE = 10000010 // Size of the input string
)

var (
	A [MAX_N]int // Array to store the input integers
	B [MAX_N]int // Array to store the sorted integers
	str string    // Buffer to store the input string
)

func getNum() int {
	// Function to read an integer from the input string
	// This function needs to be implemented based on how input is provided
	return 0 // Placeholder return
}

func putNum(n int) {
	// Function to write an integer to the output string
	str += strconv.Itoa(n) + " " // Append the number to the string
}

func CountingSort(A []int, B []int, k int, len int) {
	// Function to perform counting sort
	count := make([]int, k+1)

	for _, value := range A[:len] {
		count[value]++
	}

	for i := 1; i <= k; i++ {
		count[i] += count[i-1]
	}

	for i := len - 1; i >= 0; i-- {
		B[count[A[i]]-1] = A[i]
		count[A[i]]--
	}
}

func main() {
	var n int // Variable to store the number of integers to be read
	// The rest of the main function needs to be implemented based on the requirements
}

