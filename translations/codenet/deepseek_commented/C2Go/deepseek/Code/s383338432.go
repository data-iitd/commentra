package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var height, width int
	fmt.Scan(&height, &width)

	inputStr := make([]byte, width+1)

	// Print the top border of the output
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	// Read and print each line of input with borders
	for i := 0; i < height; i++ {
		reader := bufio.NewReader(os.Stdin)
		inputStr, _ = reader.ReadBytes('\n')
		fmt.Printf("#%s#\n", inputStr[:len(inputStr)-1])
	}

	// Print the bottom border of the output
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

