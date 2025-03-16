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
		n--
		s, _ := reader.ReadString('\n')
		s = strings.TrimSpace(s)
		for strings.Contains(s, "Hoshino") {
			index := strings.Index(s, "Hoshino")
			s = s[:index+6] + "a" + s[index+7:]
		}
		fmt.Print(s)
	}
}

