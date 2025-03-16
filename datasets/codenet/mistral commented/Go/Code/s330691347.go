package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

// Function out is used to print the output to the console
func out(x ...interface{}) {
	//	fmt.Println(x...)
}

// Initialize scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function nextInt reads an integer from the input
func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// Function nextString reads a string from the input
func nextString() string {
	sc.Scan()
	return sc.Text()
}

// Define a type Data to represent a single data point
type Data struct {
	X string
}

// Define a type Datas as a slice of Data
type Datas []Data

// Implement Len method for Datas type to get the length of the slice
func (p Datas) Len() int {
	return len(p)
}

// Implement Swap method for Datas type to swap elements in the slice
func (p Datas) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

// Implement Less method for Datas type to sort the slice based on X field
func (p Datas) Less(i, j int) bool {
	return p[i].X < p[j].X
}

// Main function starts here
func main() {
	// Initialize scanner for reading input from stdin
	sc.Split(bufio.ScanWords)

	// Read number of data points N from the input
	N := nextInt()

	// Read number of queries L from the input
	L := nextInt()

	// Initialize a slice of Data type named s with capacity N
	s := make(Datas, N)

	// Read data points X from the input and store them in the slice s
	for i := 0; i < N; i++ {
		s[i].X = nextString()
	}

	// Print the number of data points N, number of queries L, and the slice s
	out(N, L, s)

	// Sort the slice s in ascending order based on X field
	sort.Sort(s)

	// Initialize an empty string ans to store the concatenated X values
	ans := ""

	// Iterate through the slice s and concatenate X values to the string ans
	for i := 0; i < N; i++ {
		ans = ans + s[i].X
	}

	// Print the concatenated string ans to the console
	fmt.Println(ans)
}

