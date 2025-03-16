
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Read the values of T, S, and q from the user input
	scanner.Scan()
	T, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	S, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	q, _ := strconv.Atoi(scanner.Text())

	// Initialize the variable `previous` with the value of S
	previous := S

	// Initialize the variable `answer` with the value 0
	answer := 0

	// Enter a while loop that continues until `previous` is less than T
	for previous < T {
		// Inside the loop, multiply `previous` by q and increment the `answer` by 1
		previous *= q
		answer++
	}

	// After the loop, print the value of `answer`
	fmt.Println(answer)
}

