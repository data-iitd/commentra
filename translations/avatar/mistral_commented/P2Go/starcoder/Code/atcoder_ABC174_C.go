package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read an integer from standard input and return it
func ii1() int {
	var i int
	fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString(), "%d", &i)
	return i
}

// Read a string from standard input and return it
func is1() string {
	return bufio.NewReader(os.Stdin).ReadString()
}

// Read a list of integers from standard input and return it
func iia() []int {
	var a []int
	for {
		var x int
		fmt.Sscanf(bufio.NewReader(os.Stdin).ReadString(), "%d", &x)
		if x == 0 {
			break
		}
		a = append(a, x)
	}
	return a
}

// Read a list of strings from standard input and return it, split by spaces
func isa() []string {
	return strings.Split(is1(), " ")
}

func main() {
	// Set the value of k from standard input
	k := ii1()

	// Initialize a variable t to 0
	t := 0

	// Loop from 1 to k
	for i := 1; i <= k; i++ {
		// Calculate the value of t using the current value of i and k
		t = (t%k*10 + 7) % k

		// Check if t is a multiple of k
		if t == 0 {
			// Print the value of i and break out of the loop
			fmt.Println(i)
			break
		}
	}

	// If the loop completes without finding a multiple of k, print -1
	if t!= 0 {
		fmt.Println(-1)
	}
}

