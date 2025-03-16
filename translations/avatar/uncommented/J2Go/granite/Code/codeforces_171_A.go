
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
	m, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	t := reverse(m)
	fmt.Println(t + n)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	t, r := n, 0
	for t > 0 {
		r = (r * 10) + t%10
		t = t / 10
	}
	return r
}

// 