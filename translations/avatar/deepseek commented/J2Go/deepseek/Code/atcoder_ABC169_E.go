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
	reader := bufio.NewReader(os.Stdin)

	// Create a PrintWriter object to write output to the standard output
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read the number of elements 'n' from the input
	n, _ := strconv.Atoi(readLine(reader))

	// Create two ArrayList objects to store the pairs of integers
	ai := []int{}
	bi := []int{}

	// Read the pairs of integers from the input and store them in the ArrayList objects
	for i := 0; i < n; i++ {
		line := readLine(reader)
		tokens := strings.Split(line, " ")
		a, _ := strconv.Atoi(tokens[0])
		b, _ := strconv.Atoi(tokens[1])
		ai = append(ai, a)
		bi = append(bi, b)
	}

	// Sort both the ArrayList objects
	sort.Ints(ai)
	sort.Ints(bi)

	// Check if 'n' is odd or even
	if n%2 == 1 {
		// If 'n' is odd, calculate the range by subtracting the middle element of 'bi' from the middle element of 'ai' and add 1
		fmt.Fprintln(out, bi[len(bi)/2]-ai[len(ai)/2]+1)
	} else {
		// If 'n' is even, calculate the range by averaging the middle elements of 'ai' and 'bi' and multiply by 2, then add 1
		b := float64(ai[len(ai)/2]+ai[len(ai)/2-1]) / 2
		c := float64(bi[len(bi)/2]+bi[len(bi)/2-1]) / 2
		fmt.Fprintln(out, int(2*(c-b)+1))
	}
}

func readLine(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return strings.TrimSpace(line)
}

