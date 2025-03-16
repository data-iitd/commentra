package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n int
	fmt.Scan(&n)
	t := make([]string, n)
	h := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &t[i])
		fmt.Fscan(reader, &h[i])
		if strings.Compare(t[i], h[i]) < 0 {
			hanako += 3
		}
		if strings.Compare(t[i], h[i]) > 0 {
			taro += 3
		}
		if strings.Compare(t[i], h[i]) == 0 {
			taro += 1
			hanako += 1
		}
	}
	fmt.Printf("%d %d\n", taro, hanako)
}

