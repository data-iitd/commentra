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

func main() {
	// Step 4: Read two integer values from the user and store them in variables a and b.
	a, b := readTwoInts()

	// Step 5: Calculate the product of a and b, and store the result in variable x.
	x := a * b

	// Step 6: Calculate the perimeter of a rectangle with sides a and b, and store the result in variable y.
	y := (a + b) * 2

	// Step 7: Display the values of x and y.
	fmt.Printf("%d %d\n", x, y)

	// Step 8: Return 0 to indicate that the program has executed successfully.
	os.Exit(0)
}

func readTwoInts() (int, int) {
<<<<<<< HEAD
	// Step 1: Read the first line from the standard input.
	line, _ := readLine()
=======
	// Step 1: Read a line from the standard input.
	line, _ := os.Stdin.ReadString('\n')
>>>>>>> 98c87cb78a (data updated)

	// Step 2: Split the line into two strings.
	parts := strings.Split(line, " ")

	// Step 3: Convert the strings into integers.
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	return a, b
}

<<<<<<< HEAD
func readLine() (string, error) {
	// Step 1: Read a line from the standard input.
	line, err := bufio.NewReader(os.Stdin).ReadString('\n')

	// Step 2: Remove the trailing newline character.
	line = strings.TrimSuffix(line, "\n")

	return line, err
}

=======
>>>>>>> 98c87cb78a (data updated)
