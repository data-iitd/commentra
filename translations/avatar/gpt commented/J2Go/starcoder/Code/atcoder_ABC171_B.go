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
	// Set up input and output streams
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)

	// Create an instance of the Solution class to solve the problem
	sol := Solution{}

	// Call the solve method to process the input and produce output
	sol.solve(in, out)

	// Close the output stream
	out.Flush()
}

// Solution holds the data needed to solve the problem
type Solution struct {
}

// solve implements the core logic of the problem
func (s *Solution) solve(in *bufio.Reader, out *bufio.Writer) {
	// Read the number of elements (n) and the number of smallest elements to sum (k)
	n, k := readNums(in)

	// Initialize an array to hold the input numbers
	a := make([]int, n)

	// Read n integers from input and store them in the array
	for i := 0; i < n; i++ {
		a[i] = readNum(in)
	}

	// Sort the array in parallel to arrange numbers in ascending order
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })

	// Initialize a variable to hold the sum of the smallest k elements
	ans := 0

	// Sum the first k elements of the sorted array
	for i := 0; i < k; i++ {
		ans += a[i]
	}

	// Output the result (sum of the smallest k elements)
	fmt.Fprintln(out, ans)
}

// readNum reads a single integer from the input
func readNum(in *bufio.Reader) int {
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	n, _ := strconv.Atoi(s)
	return n
}

// readNums reads a list of integers from the input
func readNums(in *bufio.Reader) []int {
	s, _ := in.ReadString('\n')
	s = strings.TrimSpace(s)
	nums := strings.Split(s, " ")
	ns := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		ns[i], _ = strconv.Atoi(nums[i])
	}
	return ns
}

