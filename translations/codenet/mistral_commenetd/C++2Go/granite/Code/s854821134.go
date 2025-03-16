

package main // Begin the main package

import ( // Import the necessary libraries
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() { // Begin the main function
	reader := bufio.NewReader(os.Stdin) // Create a reader for standard input
	fmt.Println("Enter the value of a:") // Prompt the user to enter the value of a
	a, _ := reader.ReadString('\n') // Read the value of a from the standard input and store it in the variable a
	a = strings.TrimSpace(a) // Remove any leading or trailing whitespace from the value of a
	aInt, _ := strconv.Atoi(a) // Convert the value of a from string to integer and store it in the variable aInt

	fmt.Println("Enter the value of b:") // Prompt the user to enter the value of b
	b, _ := reader.ReadString('\n') // Read the value of b from the standard input and store it in the variable b
	b = strings.TrimSpace(b) // Remove any leading or trailing whitespace from the value of b
	bInt, _ := strconv.Atoi(b) // Convert the value of b from string to integer and store it in the variable bInt

	if aInt <= 8 && bInt <= 8 { // Check if both a and b are less than or equal to 8
		fmt.Println("Yay!") // If the condition is true, print "Yay!" to the standard output
	} else {
		fmt.Println(":(") // If the condition is false, print ":(" to the standard output
	}
} // End the main function

