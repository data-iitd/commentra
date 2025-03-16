package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements
	n, _ := strconv.Atoi(readLine(reader))

	// Read the elements into a list
	x := readIntSlice(reader)

	// Initialize two lists to hold elements at even and odd indices
	a := []int{}
	b := []int{}

	// Distribute elements into lists based on their index (even or odd)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i]) // Append to list 'a' if index is even
		} else {
			b = append(b, x[i]) // Append to list 'b' if index is odd
		}
	}

	// Initialize counters for occurrences of elements in lists 'a' and 'b'
	cnta := make([]int, 100002+1)
	cntb := make([]int, 100002+1)

	// Variables to track the most frequent elements in list 'a'
	vala := 0
	vala1 := 0
	maxCnta := 0
	maxCnta1 := 0

	// Count occurrences of each element in list 'a'
	for _, i := range a {
		cnta[i]++
	}

	// Find the most frequent element in list 'a'
	for _, i := range a {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}

	// Find the second most frequent element in list 'a'
	for _, i := range a {
		if maxCnta1 < cnta[i] && vala != i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	// Variables to track the most frequent elements in list 'b'
	valb := 0
	valb1 := 0
	maxCntb := 0
	maxCntb1 := 0

	// Count occurrences of each element in list 'b'
	for _, i := range b {
		cntb[i]++
	}

	// Find the most frequent element in list 'b'
	for _, i := range b {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}

	// Find the second most frequent element in list 'b'
	for _, i := range b {
		if maxCntb1 < cntb[i] && valb != i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	// Check if the most frequent elements from both lists are different
	if valb != vala {
		res := 0
		// Count elements in 'a' that are not the most frequent element
		for _, i := range a {
			if i != vala {
				res++
			}
		}
		// Count elements in 'b' that are not the most frequent element
		for _, i := range b {
			if i != valb {
				res++
			}
		}
		// Print the total count of elements that are not the most frequent
		fmt.Println(res)
	} else {
		// Initialize counters for elements not equal to the most frequent elements
		resa := 0
		resb := 0
		resa1 := 0
		resb1 := 0

		// Count elements in 'a' that are not the most frequent and second most frequent
		for _, i := range a {
			if i != vala {
				resa++
			}
			if i != vala1 {
				resa1++
			}
		}

		// Count elements in 'b' that are not the most frequent and second most frequent
		for _, i := range b {
			if i != valb {
				resb++
			}
			if i != valb1 {
				resb1++
			}
		}

		// Print the minimum of the two possible results
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

// Helper function to read a line of input
func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

// Helper function to read a slice of integers from input
func readIntSlice(reader *bufio.Reader) []int {
	line := readLine(reader)
	parts := strings.Split(line, " ")
	intSlice := []int{}
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		intSlice = append(intSlice, num)
	}
	return intSlice
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

