
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
	input, _ := reader.ReadString('\n')
	cookies := strings.Split(input, " ")
	var leftOver int64
	var takahashi int64
	leftOver, _ = strconv.ParseInt(cookies[0], 10, 64)
	leftOver -= int64(len(cookies) - 2)
	if leftOver > 0 {
		takahashi = leftOver
	} else {
		takahashi = 0
	}
	if takahashi > 0 {
		fmt.Println(takahashi, cookies[1])
	} else {
		fmt.Println(takahashi, int64(len(cookies))-1-int64(abs(leftOver)))
	}
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
