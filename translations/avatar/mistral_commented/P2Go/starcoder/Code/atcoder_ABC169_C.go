// Set the recursion limit for the function call stack
// This is necessary to prevent a "RecursionError" when dealing with large inputs
func main() {
	// Set the recursion limit to a large value
	const maxDepth = 1000000
	runtime.GOMAXPROCS(runtime.NumCPU())
	runtime.SetMaxStack(maxDepth)

	// Import other required modules
	import (
		"os"
		"fmt"
		"math"
		"strings"
		"strconv"
		"runtime"
	)

	// Define a debug function to print debug messages
	// This function is used only when running the program in an IDE or terminal
	func set_debug(something...interface{}) {
		if os.Getenv("TERM_PROGRAM")!= "" {
			fmt.Println(something...)
		}
	}
	dbg := set_debug

	// Define the input function to read input from standard input
	var input = func() string {
		s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
		return strings.TrimSpace(s)
	}

	// Define a function to read multiple integers as a list
	func LMIIS() []int {
		s := strings.Split(input(), " ")
		var a []int
		for _, v := range s {
			i, _ := strconv.Atoi(v)
			a = append(a, i)
		}
		return a
	}

	// Define input reading functions for single integer and string
	func II() int {
		s := input()
		i, _ := strconv.Atoi(s)
		return i
	}
	const P = 1000000007
	const INF = 10000000010

	// Read input for two numbers 'a' and 'b'
	sa, sb := input(), input()
	a, _ := strconv.Atoi(sa)
	b, _ := strconv.Atoi(sb)

	// Calculate the product of 'a' and 'b' and print the result
	fmt.Println(a * b / 100)
}

