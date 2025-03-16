
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
	c, _ := strconv.Atoi(read(reader))
	d, _ := strconv.Atoi(read(reader))
	fmt.Println((a - c) * (b - d))
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

