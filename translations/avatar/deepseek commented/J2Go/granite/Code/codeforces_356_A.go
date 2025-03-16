
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
	left := make([]int, n)
	for i := 0; i < n; i++ {
		left[i] = i
	}
	q, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	var answer []int
	for q > 0 {
		q--
		l, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		r, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		win, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
		for len(left) > 0 && left[0] >= l-1 && left[0] <= r-1 {
			index := left[0]
			answer = append(answer, win)
			left = left[1:]
		}
		answer[win-1] = 0
		left = append(left, win-1)
	}
	fmt.Println(strings.Join(strconv.Itoa(answer[i]) for i := 0; i < len(answer); i++))
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

