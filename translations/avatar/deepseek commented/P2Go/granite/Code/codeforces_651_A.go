
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
	input := strings.Split(strings.TrimSpace(readLine(reader)), " ")
	x, _ := strconv.Atoi(input[0])
	y, _ := strconv.Atoi(input[1])
	result := max(x+y-3+(y-x)%3>0, 0)
	fmt.Println(result)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	panic(err)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

