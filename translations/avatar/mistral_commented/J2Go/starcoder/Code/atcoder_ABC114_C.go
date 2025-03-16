
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	var i int64 = 357
	var c int = 0
	for i <= int64(N) {
		s := fmt.Sprintf("%d", i)
		if strings.Contains(s, "3") && strings.Contains(s, "5") && strings.Contains(s, "7") {
			c++
		}
		var sb strings.Builder
		var f bool = false
		for j := 0; j < len(s); j++ {
			a := s[len(s)-1-j]
			if f {
				sb.WriteByte(a)
			} else {
				if a == '3' {
					sb.WriteByte('5')
					f = true
				} else if a == '5' {
					sb.WriteByte('7')
					f = true
				} else {
					sb.WriteByte('3')
					f = true
				}
			}
		}
		if!f {
			sb.WriteByte('3')
		}
		i, _ = strconv.ParseInt(sb.String()[::-1], 10, 64)
	}
	fmt.Println(c)
}

