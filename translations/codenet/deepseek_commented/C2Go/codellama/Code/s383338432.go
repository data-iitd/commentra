package main

import "fmt"

func main() {
	var height, width, i int
	fmt.Scanf("%d %d", &height, &width)
	input_str := make([]byte, width+1)

	for i = 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i = 0; i < height; i++ {
		fmt.Scanf("%s", &input_str)
		fmt.Printf("#%s#\n", input_str)
	}

	for i = 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

