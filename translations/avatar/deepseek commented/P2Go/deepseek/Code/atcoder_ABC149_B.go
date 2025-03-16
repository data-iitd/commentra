package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var cookies []int
	input := "3 7 2" // Example input
	parts := strings.Split(input, " ")
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		cookies = append(cookies, num)
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Println(strconv.Itoa(takahashi) + " " + strconv.Itoa(cookies[1]) + (strconv.Itoa(max(0, cookies[1] - abs(leftOver)))))
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
