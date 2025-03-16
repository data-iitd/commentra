// Import necessary libraries and modules
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Define constants and global variables
var (
	N int
	S []string
	march = []string{"M", "A", "R", "C", "H"}
	march_lis = make([]int, 5)
	ans int
	INF = 1e9
	mod = 1e9 + 7
)

// Define functions if any
func main() {
	// Read input as integer
	N, _ = strconv.Atoi(readLine())
	// Read input as list of strings
	S = make([]string, N)
	for i := 0; i < N; i++ {
		S[i], _ = readLine()
	}
	// Initialize march_lis with zeros
	for i := 0; i < 5; i++ {
		march_lis[i] = 0
	}
	// Iterate through each string in S and increment the count of the corresponding marching order in march_lis
	for _, s := range S {
		if s[0] == strings.ToUpper(march[0]) {
			march_lis[0]++
		} else if s[0] == strings.ToUpper(march[1]) {
			march_lis[1]++
		} else if s[0] == strings.ToUpper(march[2]) {
			march_lis[2]++
		} else if s[0] == strings.ToUpper(march[3]) {
			march_lis[3]++
		} else if s[0] == strings.ToUpper(march[4]) {
			march_lis[4]++
		}
	}
	// Calculate the answer by finding the triple product of the counts of each marching order
	for x, y, z := range march_lis {
		ans += x * y * z
	}
	// Print the answer
	fmt.Println(ans)
}

// Function to read input as integer
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

// Function to read input as list of integers
func LIST() []int {
	var line string
	fmt.Scanln(&line)
	return STR2INTS(line)
}

// Function to read input as list of integers with given number of inputs
func ZIP(n int) [][]int {
	var line string
	fmt.Scanln(&line)
	return STR2INTS_ARRAY(line, n)
}

// Function to convert string to list of integers
func STR2INTS(str string) []int {
	var ints []int
	for _, s := range strings.Split(str, " ") {
		i, _ := strconv.Atoi(s)
		ints = append(ints, i)
	}
	return ints
}

// Function to convert string to list of integers with given number of inputs
func STR2INTS_ARRAY(str string, n int) [][]int {
	var ints [][]int
	for _, s := range strings.Split(str, " ") {
		i, _ := strconv.Atoi(s)
		ints = append(ints, []int{i})
	}
	return ints[:n]
}

// Set recursion limit
func init() {
	// Set recursion limit
	const maxDepth = 10000
	// The default stack size for a new goroutine is 256 KB.
	// The maximum stack size for a new goroutine is given by StackLimit.
	// To increase the maximum stack size, run the command
	//	ulimit -s 131072
	runtime.Stack(make([]byte, maxDepth), maxDepth)
}

// Print the answer
fmt.Println(ans)

