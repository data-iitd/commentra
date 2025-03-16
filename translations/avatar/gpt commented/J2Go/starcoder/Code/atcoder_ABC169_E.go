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
	const num = 998244353

	// Initialize BufferedReader to read input from standard input
	bf := bufio.NewReader(os.Stdin)

	// Initialize PrintWriter to output results to standard output
	out := bufio.NewWriter(os.Stdout)

	// Read the number of pairs (n) from input
	n, _ := strconv.Atoi(strings.TrimSpace(bf.ReadString()))

	// Create two slices to store the two sets of integers
	ai := make([]int, n)
	bi := make([]int, n)

	// Read n pairs of integers from input
	for i := 0; i < n; i++ {
		st := strings.Split(strings.TrimSpace(bf.ReadString()), " ")
		ai[i], _ = strconv.Atoi(st[0])
		bi[i], _ = strconv.Atoi(st[1])
	}

	// Sort both slices to prepare for median calculation
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if the number of elements is odd
	if n%2 == 1 {
		// Calculate the result for odd n using the median values
		out.WriteString(fmt.Sprintf("%d\n", bi[len(bi)/2]-ai[len(ai)/2]+1))
		out.Flush()
	} else {
		// Calculate the average of the two middle values for even n
		b := (ai[len(ai)/2] + ai[len(ai)/2-1] + 0.0) / 2
		c := (bi[len(bi)/2] + bi[len(bi)/2-1] + 0.0) / 2
		// Calculate the result for even n and print it
		out.WriteString(fmt.Sprintf("%d\n", int(2*(c-b)+1)))
		out.Flush()
	}
}

