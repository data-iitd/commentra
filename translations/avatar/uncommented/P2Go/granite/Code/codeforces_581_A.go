
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadString(' ')[0 : len(reader.ReadString(' '))-1])
	b, _ := strconv.Atoi(reader.ReadString('\n')[0 : len(reader.ReadString('\n'))-1])
	fmt.Println(min(a, b), (max(a, b)-min(a, b))/2)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
