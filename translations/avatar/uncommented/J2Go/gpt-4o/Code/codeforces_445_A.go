package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	inp, _ := reader.ReadString('\n')
	inp = strings.TrimSpace(inp)
	parts := strings.Split(inp, " ")
	n := atoi(parts[0])
	m := atoi(parts[1])
	ans := make([]string, n)

	for i := 0; i < n; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)
		var temp strings.Builder

		for j := 0; j < m; j++ {
			if str[j] == '-' {
				temp.WriteString("-")
			} else {
				if (i+j)%2 == 1 {
					temp.WriteString("W")
				} else {
					temp.WriteString("B")
				}
			}
		}
		ans[i] = temp.String()
	}

	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

func atoi(s string) int {
	var n int
	for _, c := range s {
		n = n*10 + int(c-'0')
	}
	return n
}
