// Importing necessary Go libraries for reading input from the console and handling exceptions
import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

// Main function is the entry point of the Go application
func main() {

	// Creating a bufio.Scanner object to read input from the console
	scanner := bufio.NewScanner(os.Stdin)

	// Reading a single line of input from the console and storing it as a string array
	scanner.Scan()
	str := scanner.Text()

	// Parsing the first two elements of the string array as integers 'h' and 'a' respectively
	h, _ := strconv.Atoi(str[0])
	a, _ := strconv.Atoi(str[1])

	// Initializing a variable 'num' to keep track of the number of steps
	num := 0

	// Using a for loop to simulate the given condition
	for i := 1; h > 0; i++ {

		// Subtracting 'a' from 'h' in each iteration
		h = h - a

		// Incrementing the 'num' variable after each successful subtraction
		num++
	}

	// Printing the final result 'num' to the console
	fmt.Println(num)
}

