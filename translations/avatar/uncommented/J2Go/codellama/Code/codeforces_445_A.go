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
	fmt.Scan(&n, &m)
	ans := make([]string, n)
	for i := 0; i < n; i++ {
		str := bufio.NewScanner(os.Stdin)
		str.Scan()
		temp := strings.Builder{}
		for j := 0; j < m; j++ {
			if str.Text()[j] == '-' {
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

