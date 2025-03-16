// Importing necessary packages for input and output
import (
	"fmt"
	"os"
	"strconv"
)

// Main function is the entry point of the Go application
func main() {
	// Initialize Scanner object to read input from standard input
	sc := bufio.NewScanner(os.Stdin)

	// Read first integer input A from user
	sc.Scan()
	A, _ := strconv.Atoi(sc.Text())

	// Read second integer input B from user
	sc.Scan()
	B, _ := strconv.Atoi(sc.Text())

	// Initialize variables for storing remainders and result
	amari := 0
	result := 0

	// Calculate the result by dividing B by A - 1 and storing the quotient
	result = (B - 1) / (A - 1)

	// Calculate the remainder of B divided by A - 1 and store it in amari
	amari = (B - 1) % (A - 1)

	// Check if the remainder is not zero
	if amari != 0 {
		// If the remainder is not zero, increment the result by 1
		result += 1
	}

	// Initialize PrintWriter object to write output to standard output
	out := bufio.NewWriter(os.Stdout)

	// Write the result to the standard output
	fmt.Fprintln(out, result)

	// Close the Scanner object to release system resources
	sc.Close()

	// Flush the PrintWriter buffer to write the output immediately
	out.Flush()
}

