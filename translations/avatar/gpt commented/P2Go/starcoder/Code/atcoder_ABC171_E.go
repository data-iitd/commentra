package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input N (not used in further calculations)
	var N int
	fmt.Scanf("%d", &N)

	// Read a list of integers from input and convert them to a list of integers
	var a []int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	for _, s := range strings.Split(scanner.Text(), " ") {
		i, _ := strconv.Atoi(s)
		a = append(a, i)
	}

	// Calculate the total using the XOR operation across all elements in the list 'a'
	total := 0
	for _, ai := range a {
		total ^= ai
	}

	// For each element in the list 'a', compute the XOR with 'total' and print the results
	// The results are converted to strings and joined with a space for output
	for _, ai := range a {
		fmt.Printf("%d ", ai^total)
	}
}

