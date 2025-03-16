
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.ParseInt(read(reader), 10, 64)
	b, _ := strconv.ParseInt(read(reader), 10, 64)
	fmt.Println(max(a+b, max(a-b, a*b)))
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

