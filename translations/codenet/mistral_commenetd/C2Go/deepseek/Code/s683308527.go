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
	var s string
	var c string

	fmt.Scan(&n)

	for n > 0 {
		s, _ = reader.ReadString('\n')
		s = strings.TrimSpace(s)

		for strings.Contains(s, "Hoshino") {
			c = strings.Replace(s, "Hoshino", "aana", 1)
			s = c
		}

		fmt.Print(s)
		n--
	}
}

