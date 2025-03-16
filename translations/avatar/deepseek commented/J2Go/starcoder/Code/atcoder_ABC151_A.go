
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Read a single line of input from the user
	input, _ := reader.ReadString('\n')

	// Convert the input to a slice of integers
	inputSlice := strings.Split(input, " ")
	inputIntSlice := make([]int, len(inputSlice))
	for i := 0; i < len(inputSlice); i++ {
		inputIntSlice[i], _ = strconv.Atoi(inputSlice[i])
	}

	// Increment the first character of the input by 1 and print it
	fmt.Printf("%c", rune(inputIntSlice[0]+1))
}

