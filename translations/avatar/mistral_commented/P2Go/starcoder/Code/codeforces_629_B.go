
// Importing the "bufio" and "os" modules for reading input from the standard input
import (
	"bufio"
	"os"
)

// Assigning the function "Scan" to the variable "input" for reading lines from standard input
var input = bufio.NewScanner(os.Stdin)

// Initializing the array m with zeros for all indices up to N
const N = 368
var m [N]int

// Initializing the array f with zeros for all indices up to N
var f [N]int

// Reading the number of operations from the standard input and processing each operation
func main() {
	// Reading the number of operations from the standard input
	var n int
	input.Scan()
	n, _ = strconv.Atoi(input.Text())

	// Reading the operations from the standard input and processing each operation
	for i := 0; i < n; i++ {
		// Reading an operation line and splitting it into components
		var x string
		var a, b int
		input.Scan()
		x = strings.Split(input.Text(), " ")[0]
		a, _ = strconv.Atoi(strings.Split(input.Text(), " ")[1])
		b, _ = strconv.Atoi(strings.Split(input.Text(), " ")[2])
		b += 1

		// If the operation is "M", updating the m array accordingly
		if x == "M" {
			m[a] += 2
			m[b] -= 2
		}

		// If the operation is "F", updating the f array accordingly
		else {
			f[a] += 2
			f[b] -= 2
		}
	}

	// Initializing three variables a, b, and c with zeros
	var a, b, c int

	// Calculating the prefix sums of m and f arrays
	for i := 0; i < N; i++ {
		// Updating the variables a and b with the sum of m and f arrays respectively
		a += m[i]
		b += f[i]
		// Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
		if min(a, b) > c {
			c = min(a, b)
	}

	// Printing the result, which is the minimum of the prefix sums of m and f arrays
	fmt.Println(c)
}

// Finding the minimum of a and b
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// END-OF-CODE
