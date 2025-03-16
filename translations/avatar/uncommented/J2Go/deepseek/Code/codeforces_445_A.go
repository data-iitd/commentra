package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	inputs := strings.Split(strings.TrimSpace(input), "")
	n := parseInt(inputs[0])
	m := parseInt(inputs[1])
	ans := make([]string, n)
	for i := 0; i < n; i++ {
		str, _ := reader.ReadString('\n')
		str = strings.TrimSpace(str)
		temp := strings.Builder{}
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

func parseInt(s string) int {
	var result int
	for _, char := range s {
		result = result*10 + int(char-'0')
	}
	return result
}

