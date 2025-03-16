
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	K, _ := strconv.Atoi(read(reader))
	X, _ := strconv.Atoi(read(reader))
	for i := X - K + 1; i <= X+K-1; i++ {
		fmt.Print(i)
		if i < X+K-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

