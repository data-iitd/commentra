package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	parts := strings.Split(input, " ")
	cookies := make([]int, len(parts))
	for i, part := range parts {
		cookies[i], _ = strconv.Atoi(part)
	}

	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)

	if takahashi > 0 {
		fmt.Println(strconv.Itoa(takahashi) + " " + strconv.Itoa(cookies[1]))
	} else {
		fmt.Println(strconv.Itoa(takahashi) + " " + strconv.Itoa(max(0, cookies[1]-abs(leftOver))))
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
