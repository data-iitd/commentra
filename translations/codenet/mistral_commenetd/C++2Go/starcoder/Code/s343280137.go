<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants definition
const MOD = 1000000007

// Function to calculate maximum sum of subarray
<<<<<<< HEAD
func maxSubarray(x []int, c int) int {
	// Declare and initialize two vectors x and v of size n+1 with zero values
	n := len(x)
	v := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		v[i] = v[i-1] + x[i-1]
	}

	// Calculate left prefix sums
	lefttotal := make([]int, n+1)
	maxlefttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
	}

	// Calculate right prefix sums
	righttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		righttotal[i] = righttotal[i-1] + v[n-i+1]
=======
func maxSubarray(x []int, v []int, n int, c int) int {
	// Declare and initialize two vectors lefttotal and righttotal of size n+1 with zero values
	lefttotal := make([]int, n+1)
	righttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		lefttotal[i] = lefttotal[i-1] + v[i]
		righttotal[i] = righttotal[i-1] + v[n-i+1]
	}

	// Declare and initialize two vectors maxlefttotal and maxrighttotal of size n+1 with zero values
	maxlefttotal := make([]int, n+1)
	maxrighttotal := make([]int, n+1)
	for i := 1; i < n+1; i++ {
		maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
>>>>>>> 98c87cb78a (data updated)
		maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
	}

	// Calculate answer
	ans := 0
	for i := 1; i < n+1; i++ {
		ans = max(ans, lefttotal[i]-x[i])
		ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])
		ans = max(ans, righttotal[i]-(c-x[n+1-i]))
		ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])
	}

	return ans
}

// Function to read input from stdin
<<<<<<< HEAD
func readInput(reader *bufio.Reader) (x []int, c int) {
	// Read input values for n and c from standard input
	line, _ := reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimSuffix(line, "\r")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r\n")
	line = strings.TrimSuffix(line, "\n\r")
	line = strings.TrimSuffix(line, "\r
=======
func readInput(reader *bufio.Reader) (n int, c int, x []int, v []int) {
	// Read input values for n and c from standard input
	line, _ := reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	n, _ = strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSuffix(line, "\n")
	c, _ = strconv.Atoi(line)

	// Declare and initialize two vectors x and v of size n+1 with zero values
	x = make([]int, n+1)
	v = make([]int, n+1)
	for i := 1; i < n+1; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSuffix(line, "\n")
		x[i], _ = strconv.Atoi(strings.Split(line, " ")[0])
		v[i], _ = strconv.Atoi(strings.Split(line, " ")[1])
	}

	return n, c, x, v
}

// Function to print output to stdout
func printOutput(ans int) {
	// Print answer to standard output
	fmt.Println(ans)
}

// Main function
func main() {
	// Tie input and output streams to prevent buffer flush
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	// Read input values from stdin
	n, c, x, v := readInput(reader)

	// Calculate maximum sum of subarray
	ans := maxSubarray(x, v, n, c)

	// Print answer to stdout
	printOutput(ans)
}

>>>>>>> 98c87cb78a (data updated)
