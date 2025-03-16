
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Step 3: Declare variables
	var a, b int

	// Step 4: Read input values
	// Use bufio.NewReader to read input values from the user.
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	values := strings.Split(input, " ")
	a, _ = strconv.Atoi(values[0])
	b, _ = strconv.Atoi(values[1])

	// Step 5: Perform calculations
	// Calculate the result based on the input values.
	result := 6 - a - b

	// Step 6: Output the result
	// Use fmt.Println to display the result.
	fmt.Println(result)
}

