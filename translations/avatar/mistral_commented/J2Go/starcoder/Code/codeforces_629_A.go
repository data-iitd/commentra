// Importing necessary packages
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Declaring the main function
func main() {

	// Declaring the variables to store the number of strings and the final result
	var num int
	var fine int

	// Declaring the variables to store the input from the user
	var input string
	var inputArr []string

	// Declaring the variables to store the number of 'C' characters in each string
	var counter int

	// Declaring the variables to store the current string and the current character
	var s string
	var c string

	// Creating a new scanner object to read input from the user
	reader := bufio.NewReader(os.Stdin)

	// Taking the number of strings as input from the user
	fmt.Print("Enter the number of strings: ")
	input, _ = reader.ReadString('\n')
	num, _ = strconv.Atoi(strings.TrimSpace(input))

	// Creating a new array of strings to store the input from the user
	inputArr = make([]string, num)

	// Taking the input from the user
	for i := 0; i < num; i++ {
		fmt.Print("Enter the string: ")
		input, _ = reader.ReadString('\n')
		inputArr[i] = strings.TrimSpace(input)
	}

	// Iterating through each string
	for i := 0; i < num; i++ {

		// Iterating through each character in the current string
		for k := 0; k < num; k++ {

			// Checking if the current character is 'C'
			if inputArr[i][k] == 'C' {

				// Incrementing the counter variable
				counter++
			}
		}

		// Calculating the fine based on the number of 'C' characters in the current string
		fine += (counter * (counter - 1)) / 2

		// Resetting the counter variable for the next string
		counter = 0
	}

	// Iterating through each string again
	for i := 0; i < num; i++ {

		// Iterating through each character in the current string
		for k := 0; k < num; k++ {

			// Checking if the current character is 'C'
			if inputArr[k][i] == 'C' {

				// Incrementing the counter variable
				counter++
			}
		}

		// Calculating the fine based on the number of 'C' characters in the current string
		fine += (counter * (counter - 1)) / 2

		// Resetting the counter variable for the next string
		counter = 0
	}

	// Printing the final result
	fmt.Println(fine)
}

