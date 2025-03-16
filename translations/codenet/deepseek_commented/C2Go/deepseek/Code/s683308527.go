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
	for n > 0 {
		s, _ := reader.ReadString('\n')
		for strings.Contains(s, "Hoshino") {
			s = strings.Replace(s, "Hoshino", "Hoshina", 1)
		}
		fmt.Print(s)
		n--
	}
}

