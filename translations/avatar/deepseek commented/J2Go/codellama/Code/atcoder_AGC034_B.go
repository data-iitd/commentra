
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	s = strings.Replace(s, "BC", "D", -1)
	var cnt int64
	var tmp int64
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			tmp++
		} else if s[i] == 'D' {
			cnt += tmp
		} else {
			tmp = 0
		}
	}
	fmt.Println(cnt)
}

// The Go code uses the bufio package to read input from the user. The strings package is used to replace all occurrences of "BC" with "D".

