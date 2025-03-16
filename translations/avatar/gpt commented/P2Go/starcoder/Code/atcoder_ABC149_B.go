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
	parts := strings.Split(line, " ")
	cookies := make([]int, 3)
	for i := 0; i < 3; i++ {
		cookies[i], _ = strconv.Atoi(parts[i])
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Printf("%d %d\n", takahashi, max(0, cookies[1]-abs(leftOver)))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

