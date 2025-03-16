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

	T := make(map[string]bool)

	for i := 0; i < n; i++ {
		com, _ := reader.ReadString(' ')
		reader.ReadString('\n')
		str, _ := reader.ReadString('\n')

		com = strings.TrimSpace(com)
		str = strings.TrimSpace(str)

		if com[0] == 'i' {
			T[str] = true
		} else {
			if T[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

