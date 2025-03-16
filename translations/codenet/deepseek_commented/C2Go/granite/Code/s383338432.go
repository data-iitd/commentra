
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter height: ")
	height, _ := strconv.Atoi(reader.ReadLine()[0])

	fmt.Print("Enter width: ")
	width, _ := strconv.Atoi(reader.ReadLine()[0])

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i := 0; i < height; i++ {
		fmt.Print("#")
		fmt.Print(reader.ReadLine()[0])
		fmt.Println("#")
	}

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

