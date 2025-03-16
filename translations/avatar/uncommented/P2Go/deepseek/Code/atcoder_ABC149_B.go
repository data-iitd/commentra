package main

import (
	"fmt"
	"strconv"
)

func main() {
	var cookies []int
	var input string
	fmt.Scan(&input)
	for _, value := range input.Split(" ") {
		num, _ := strconv.Atoi(value)
		cookies = append(cookies, num)
	}
	leftOver := cookies[0] - cookies[2]
	takahashi := max(0, leftOver)
	fmt.Println(strconv.Itoa(takahashi) + " " + (strconv.Itoa(cookies[1]) if takahashi > 0 else strconv.Itoa(max(0, cookies[1] - abs(leftOver)))))
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
