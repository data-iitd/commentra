package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Initializing FastReader for reading input
	in := NewFastReader()

	n := in.nextInt() // Reading the number of elements in the array

	// Creating a TreeSet to store the indices of elements in the sorted order
	left := make(map[int]bool)
	// Creating an array to store the answer for each index
	answer := make([]int, n)

	// Adding all the indices to the TreeSet and initializing the answer array with -1
	for i := 0; i < n; i++ {
		left[i] = true
		answer[i] = -1
	}

	q := in.nextInt() // Reading the number of queries

	// Processing each query
	for i := 0; i < q; i++ {
		l := in.nextInt() - 1 // Reading the left index of the query range
		r := in.nextInt() - 1 // Reading the right index of the query range
		win := in.nextInt()  // Reading the winning index

		// Updating the answer for the winning index and all the indices between the left and right indices
		for k := range left {
			if k >= l && k <= r {
				answer[k] = win
				delete(left, k)
			}
		}

		// Updating the answer for the winning index in the answer array
		answer[win-1] = 0

		// Adding the winning index back to the TreeSet
		left[win-1] = true
	}

	// Creating a StringBuilder to store the answer as a string
	var ans strings.Builder

	// Printing the answer for each index in the answer array
	for i := 0; i < n; i++ {
		ans.WriteString(strconv.Itoa(answer[i]))
		if i != n-1 {
			ans.WriteString(" ")
		}
	}

	fmt.Println(ans.String()) // Printing the answer as a single line
}

type FastReader struct {
	sc *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{sc: bufio.NewScanner(os.Stdin)}
}

func (r *FastReader) next() string {
	r.sc.Scan()
	return r.sc.Text()
}

func (r *FastReader) nextInt() int {
	num, _ := strconv.Atoi(r.next())
	return num
}

func (r *FastReader) nextLong() int64 {
	num, _ := strconv.ParseInt(r.next(), 10, 64)
	return num
}

func (r *FastReader) nextDouble() float64 {
	num, _ := strconv.ParseFloat(r.next(), 64)
	return num
}

func (r *FastReader) nextLine() string {
	return r.next()
}

