
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

	var result int
	if a > b {
		result = 2*a - 1
	} else if a == b {
		result = 2 * a
	} else {
		result = 2*b - 1
	}
	fmt.Println(result)
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

