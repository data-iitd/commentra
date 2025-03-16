
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(read(reader))
	b, _ := strconv.Atoi(read(reader))
	if a <= 8 && b <= 8 {
		fmt.Println("Yay!")
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

