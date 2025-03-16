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
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	ans := 0
	for i := 0; i < n; i++ {
		x, _ := reader.ReadString('\n')
		x = strings.TrimSpace(x)
		a, b := 0, 0
		for _, j := range s {
			if string(j) == x[0] {
				a++
			} else if string(j) == x[1] {
				b++
			} else {
				ans += min(a, b)
				a, b = 0, 0
			}
		}
		ans += min(a, b)
	}
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

