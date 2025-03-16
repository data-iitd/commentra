
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
	// Declare and initialize a constant integer
	num := 998244353

	// Create a BufferedReader object to read input from the standard input
	bf := bufio.NewReader(os.Stdin)

	// Create a PrintWriter object to write output to the standard output
	out := bufio.NewWriter(os.Stdout)

	// Read the number of elements 'n' from the input
	n, _ := strconv.Atoi(bf.ReadString('\n'))

	// Create two ArrayList objects to store the pairs of integers
	ai := make([]int, 0)
	bi := make([]int, 0)

	// Read the pairs of integers from the input and store them in the ArrayList objects
	for i := 0; i < n; i++ {
		st := strings.Split(bf.ReadString('\n'), " ")
		ai = append(ai, strconv.Atoi(st[0]))
		bi = append(bi, strconv.Atoi(st[1]))
	}

	// Sort both the ArrayList objects
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if 'n' is odd or even
	if n%2 == 1 {
		// If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
		fmt.Fprintln(out, bi[len(bi)/2]-ai[len(ai)/2]+1)
		out.Flush()
	} else {
		// If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
		b := (float64(ai[len(ai)/2]) + float64(ai[len(ai)/2-1]) + 0.0) / 2
		c := (float64(bi[len(bi)/2]) + float64(bi[len(bi)/2-1]) + 0.0) / 2
		fmt.Fprintln(out, int((2*c-b)+1))
		out.Flush()
	}
}

