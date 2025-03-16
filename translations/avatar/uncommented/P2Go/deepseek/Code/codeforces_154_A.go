package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	var n int
	fmt.Scan(&n)
	ans := 0
	for i := 0; i < n; i++ {
		x, _ := reader.ReadString('\n')
		a, b := 0, 0
		for _, j := range s {
			if j == rune(x[0]) {
				a += 1
			} else if j == rune(x[1]) {
				b += 1
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
