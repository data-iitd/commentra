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
	var com, str string
	m := make(map[string]bool)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		com, _ = reader.ReadString('\n')
		com = strings.TrimSpace(com)
		str, _ = reader.ReadString('\n')
		str = strings.TrimSpace(str)

		if com[0] == 'i' {
			m[str] = true
		} else {
			if m[str] {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

