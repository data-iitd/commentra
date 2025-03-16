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
	line, _ := reader.ReadString('\n')
	cookies := strings.Split(line, " ")
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Printf("%s %s\n", takahashi, max(0, cookies[1]-abs(leftOver)))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

