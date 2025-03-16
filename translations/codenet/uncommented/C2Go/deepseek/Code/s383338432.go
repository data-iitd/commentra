package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter height and width: ")
	input, _ := reader.ReadString('\n')
	var height, width int
	fmt.Sscanf(input, "%d %d", &height, &width)

	
	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i := 0; i < height; i++ {
		inputStr, _ := reader.ReadString('\n')
		fmt.Printf("#%s#\n", inputStr[:len(inputStr)-1])
	}

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

