
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	r, _ := strconv.Atoi(read(reader))

	fmt.Println(r * r)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	return s
}

