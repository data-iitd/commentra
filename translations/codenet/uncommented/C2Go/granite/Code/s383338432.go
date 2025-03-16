
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	height, _ := strconv.Atoi(nextString(reader))
	width, _ := strconv.Atoi(nextString(reader))

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()

	for i := 0; i < height; i++ {
		fmt.Printf("#%s#\n", nextString(reader))
	}

	for i := 0; i < width+2; i++ {
		fmt.Print("#")
	}
	fmt.Println()
}

func nextString(reader *bufio.Reader) string {
	str, _ := reader.ReadString('\n')
	return str
}

