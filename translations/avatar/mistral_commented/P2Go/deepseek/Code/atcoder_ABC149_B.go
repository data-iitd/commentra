package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)
	cookies := []int{}
	for _, x := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(x)
		cookies = append(cookies, num)
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
