package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Define a constant number for modulo operations
	num := 998244353

	// Initialize BufferedReader to read input from standard input
	bf := bufio.NewReader(os.Stdin)

	// Initialize PrintWriter to output results to standard output
	out := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) from input
	n, _ := strconv.Atoi(bf.ReadString('\n'))

	// Create two ArrayLists to store the two sets of integers
	ai := make([]int, 0)
	bi := make([]int, 0)

	// Read n pairs of integers from input
	for i := 0; i < n; i++ {
		st := strings.Split(bf.ReadString('\n'), " ")
		// Add the first integer of the pair to the first list
		ai = append(ai, strconv.Atoi(st[0]))
		// Add the second integer of the pair to the second list
		bi = append(bi, strconv.Atoi(st[1]))
	}

	// Sort both lists to prepare for median calculation
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if the number of elements is odd
	if n%2 == 1 {
		// Calculate the result for odd n using the median values
		fmt.Fprintln(out, bi[len(bi)/2]-ai[len(ai)/2]+1)
		out.Flush()
	} else {
		// Calculate the average of the two middle values for even n
		b := (float64(ai[len(ai)/2]) + float64(ai[len(ai)/2-1]) + 0.0) / 2
		c := (float64(bi[len(bi)/2]) + float64(bi[len(bi)/2-1]) + 0.0) / 2
		// Calculate the result for even n and print it
		fmt.Fprintln(out, int(2*(c-b)+1))
		out.Flush()
	}
}

