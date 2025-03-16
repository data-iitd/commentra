
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	left := make([]bool, n)
	for i := 0; i < n; i++ {
		left[i] = true
	}
	q, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	var answer []int
	for i := 0; i < n; i++ {
		answer = append(answer, 0)
	}
	for q > 0 {
		q--
		l, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		win, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		for i := l - 1; i <= r-1; i++ {
			if left[i] {
				answer[i] = win
				left[i] = false
			}
		}
		answer[win-1] = 0
		left[win-1] = true
	}
	for _, v := range answer {
		fmt.Print(v, " ")
	}
	fmt.Println()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

