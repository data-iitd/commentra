<<<<<<< HEAD

=======
_

package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to solve the problem
<<<<<<< HEAD
func solve() {
=======
func solve () {
>>>>>>> 98c87cb78a (data updated)
	var ans int64 = 0 // Initialize the answer variable
	var n int // Read the number of nodes

	// Calculate the contribution of each node to the answer
	for i := 1; i <= n; i++ {
<<<<<<< HEAD
		ans += int64(i) * int64(n-i+1) // Contribution of node i
=======
		ans += int64(i) * int64(n - i + 1) // Contribution of node i
>>>>>>> 98c87cb78a (data updated)
	}

	// Adjust the answer based on the edges between nodes
	for i := 1; i < n; i++ {
		var u, v int // Read the edge connecting nodes u and v
		fmt.Scanf("%d %d", &u, &v)
		a := max(u, v) // Determine the maximum node
		b := min(u, v) // Determine the minimum node
<<<<<<< HEAD
		ans -= int64(b) * int64(n-a+1) // Subtract the contribution of the edge
=======
		ans -= int64(b) * int64(n - a + 1) // Subtract the contribution of the edge
>>>>>>> 98c87cb78a (data updated)
	}

	// Output the final answer
	fmt.Println(ans)
}

<<<<<<< HEAD
func main() {
	// Uncomment the following lines for file input/output during local testing
	// fmt.Scanf("%d", &t)
	// for i := 0; i < t; i++ {
	//     solve()
	// }
	solve()
=======
func main () {
	// Uncomment the following lines for file input/output during local testing
	// reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)
	// writer := bufio.NewWriterSize(os.Stdout, 1024 * 1024)
	// defer writer.Flush()
	// reader = os.Stdin

	// Read the number of test cases
	// t, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t := 1

	// Run the test cases
	for ; t > 0; t-- {
		solve()
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
>>>>>>> 98c87cb78a (data updated)
}

