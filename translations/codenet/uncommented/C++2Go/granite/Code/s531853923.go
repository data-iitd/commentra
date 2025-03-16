
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
	if a*b%2 == 1 && (c+d)%2 == 1 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}
