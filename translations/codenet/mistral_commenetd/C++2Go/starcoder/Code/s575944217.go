
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)
import (
"fmt"
"os"
"strconv"
"strings"
)

// Global variables
var (
n int
)

// Function to read input from stdin
<<<<<<< HEAD
func readInput(reader *bufio.Reader) {
// Read the number of vertices from the input
fmt.Fscan(reader, &n)
}

// Function to print output to stdout
func printOutput(writer *bufio.Writer, ans []int) {
// Print the answer vector
for i := 0; i < n; i++ {
fmt.Fprintln(writer, ans[i])
=======
func readInput() {
// Read the number of vertices from the input
fmt.Scanf("%d\n", &n)
}

// Function to print output to stdout
func printOutput(ans []int) {
// Print the answer vector
for i := 0; i < n; i++ {
fmt.Printf("%d\n", ans[i])
>>>>>>> 98c87cb78a (data updated)
}
}

// Main function starts here
func main() {
// Read input from stdin
<<<<<<< HEAD
reader := bufio.NewReader(os.Stdin)
readInput(reader)
=======
readInput()
>>>>>>> 98c87cb78a (data updated)

// Initialize an answer vector of size n
ans := make([]int, n)

// Read the edges and increment the count of each vertex in the answer vector
for i := 0; i < n-1; i++ {
var a int
<<<<<<< HEAD
fmt.Fscan(reader, &a)
=======
fmt.Scanf("%d\n", &a)
>>>>>>> 98c87cb78a (data updated)
a--
ans[a]++
}

// Print the answer vector
<<<<<<< HEAD
printOutput(os.Stdout, ans)
=======
printOutput(ans)
>>>>>>> 98c87cb78a (data updated)
}

