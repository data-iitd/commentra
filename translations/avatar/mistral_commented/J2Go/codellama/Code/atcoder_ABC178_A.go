// Importing necessary Go libraries for this program
import (
	"fmt"
	"strconv"
)

// Main function is the entry point of the Go application
func main() {
	// Creating a new Scanner object to read user input from the standard input
	scan := bufio.NewScanner(os.Stdin)

	// Reading an integer value from the user input
	var x int
	fmt.Scan(&x)

	// Determining a boolean value based on the condition x equals to 1
	var bool bool
	if x == 1 {
		bool = true
	} else {
		bool = false
	}

	// Calculating the result based on the boolean value
	var result int
	if !bool {
		result = 1
	} else {
		result = 0
	}

	// Creating a new PrintWriter object to write the output to the standard output
	out := bufio.NewWriter(os.Stdout)

	// Writing the result to the standard output
	fmt.Fprintln(out, result)

	// Flushing the PrintWriter buffer to ensure the output is written immediately
	out.Flush()

	// Closing the Scanner object to release system resources
	scan.Close()
}

