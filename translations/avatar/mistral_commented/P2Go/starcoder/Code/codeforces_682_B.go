package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Function to read a list of integers from standard input
func I() []int {
	var a []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}
	return a
}

// Function to read an integer from standard input
func IS() int {
	var a int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	a, _ = strconv.Atoi(scanner.Text())
	return a
}

// Function to read an integer from standard input and convert it to an integer
func IN() int {
	return IS()
}

// Function to read a float from standard input
func IF() float64 {
	var a float64
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	a, _ = strconv.ParseFloat(scanner.Text(), 64)
	return a
}

func main() {
	// Read the number of test cases 'n'
	n := IN()

	// Read the list 'l' of length 'n' containing 'n' integers
	l := I()

	// Initialize variable 'f' to 1
	f := 1

	// Sort the list 'l' in ascending order
	sort.Ints(l)

	// Initialize variable 'c' to 0
	c := 0

	// Iterate through the list 'l'
	for i := range l {
		// If the current element 'i' is greater than the previous count 'c', increment 'c' by 1
		if l[i] > c {
			c += 1
	}

	// Print the final result, which is the number of unique elements in the list 'l' plus 1
	fmt.Println(c + 1)
}

