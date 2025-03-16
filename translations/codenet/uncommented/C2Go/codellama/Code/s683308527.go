package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var n int
	var s string
	var c string
	fmt.Scanf("%d%*c", &n)
	for n > 0 {
		n--
		scanner := bufio.NewScanner(os.Stdin)
		scanner.Scan()
		s = scanner.Text()
		for {
			c = strings.Index(s, "Hoshino")
			if c == -1 {
				break
			}
			s = s[:c+6] + "a" + s[c+7:]
		}
		fmt.Println(s)
	}
}

