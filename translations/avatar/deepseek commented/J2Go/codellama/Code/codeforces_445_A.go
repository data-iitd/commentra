package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	var inp []string
	var ans []string

	reader := bufio.NewReader(os.Stdin)
	inp = strings.Split(reader.ReadString('\n'), "")
	n, _ = strconv.Atoi(inp[0])
	m, _ = strconv.Atoi(inp[1])

	for i := 0; i < n; i++ {
		str := reader.ReadString('\n')
		temp := ""

		for j := 0; j < m; j++ {
			if string(str[j]) == "-" {
				temp += "-"
			} else {
				if (i+j)%2 == 1 {
					temp += "W"
				} else {
					temp += "B"
				}
			}
		}
		ans = append(ans, temp)
	}

	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

