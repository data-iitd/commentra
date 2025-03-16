
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	x, _ := strconv.ParseInt(readLine(reader), 10, 64)
	y, _ := strconv.ParseInt(readLine(reader), 10, 64)
	if int(abs(x-y)) <= 1 {
		fmt.Println("Brown")
	} else {
		fmt.Println("Alice")
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
