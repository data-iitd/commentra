// Package name
package main

// Import necessary libraries for various functionalities
import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

// Set up input reading methods for efficiency
var (
	read = bufio.NewReader(os.Stdin).Read
	readline = bufio.NewReader(os.Stdin).ReadString
	readlines = bufio.NewReader(os.Stdin).ReadBytes
)

// Set recursion limit to handle deep recursion cases
const RECURSION_LIMIT = 100000000

// Define constants for infinity and modulo operations
const INF = 1000000000
const MOD = 1000000007

func main() {
	// Read input string
	s := readline()

	// Check if all characters in the string are the same
	if len(strings.Split(s, "")) == 1 {
		fmt.Println(0)  // If true, print 0 and exit
		os.Exit(0)
	}

	// Count the occurrences of each character in the string
	a := make(map[string]int)
	for _, c := range s {
		a[string(c)]++
	}

	// Calculate the answer as twice the minimum frequency of any character
	ans := 0
	for _, v := range a {
		if ans == 0 || v < ans {
			ans = v * 2
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

// Entry point of the program
func init() {
	// Set recursion limit to handle deep recursion cases
	runtime.GOMAXPROCS(RECURSION_LIMIT)
}

