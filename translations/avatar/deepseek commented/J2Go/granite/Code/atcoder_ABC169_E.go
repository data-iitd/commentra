

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
	const num = 998244353
	// Create a BufferedReader object to read input from the standard input
	bf := bufio.NewReader(os.Stdin)
	// Create a PrintWriter object to write output to the standard output
	out := bufio.NewWriter(os.Stdout)
	// Read the number of elements 'n' from the input
	n, _ := strconv.Atoi(bf.ReadLine())
	// Create two slices to store the pairs of integers
	ai := make([]int, n)
	bi := make([]int, n)
	// Read the pairs of integers from the input and store them in the slices
	for i := 0; i < n; i++ {
		s := strings.Split(bf.ReadLine(), " ")
		ai[i], _ = strconv.Atoi(s[0])
		bi[i], _ = strconv.Atoi(s[1])
	}
	// Sort both the slices
	sort.Ints(ai)
	sort.Ints(bi)
	// Check if 'n' is odd or even
	if n%2 == 1 {
		// If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
		out.WriteString(strconv.Itoa(bi[n/2]-ai[n/2]+1) + "\n")
	} else {
		// If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
		b := (float64(ai[n/2]+ai[n/2-1]) / 2)
		c := (float64(bi[n/2]+bi[n/2-1]) / 2)
		out.WriteString(strconv.Itoa(int((2*(c-b))+1)) + "\n")
	}
	// Flush the PrintWriter object to write the output to the standard output
	out.Flush()
}

