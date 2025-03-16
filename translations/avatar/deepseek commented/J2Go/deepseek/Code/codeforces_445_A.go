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
	inputs := strings.Split(strings.TrimSpace(input), "")
	n, _ := strconv.Atoi(inputs[0])
	m, _ := strconv.Atoi(inputs[1])

	ans := make([]string, n)

	for i := 0; i < n; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		var temp strings.Builder

		for j := 0; j < m; j++ {
			if line[j] == '-' {
				temp.WriteByte('-')
			} else {
				if (i+j)%2 == 1 {
					temp.WriteByte('W')
				} else {
					temp.WriteByte('B')
				}
			}
		}
		ans[i] = temp.String()
	}

	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}
