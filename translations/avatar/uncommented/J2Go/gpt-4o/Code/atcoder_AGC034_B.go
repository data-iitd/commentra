package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	s = strings.ReplaceAll(s, "BC", "D")
	cnt := int64(0)
	tmp := int64(0)

	for _, char := range s {
		if char == 'A' {
			tmp++
		} else if char == 'D' {
			cnt += tmp
		} else {
			tmp = 0
		}
	}

	fmt.Println(cnt)
}

// <END-OF-CODE>
