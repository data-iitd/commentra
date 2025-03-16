package main

import (
	"fmt"
)

func main() {
	var height, width int
	fmt.Scan(&height, &width)
	inputStr := make([]byte, width)

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i := 0; i < height; i++ {
		fmt.Scanf("%s", &inputStr)
		fmt.Printf("#%s#\n", inputStr)
	}

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

// <END-OF-CODE>
