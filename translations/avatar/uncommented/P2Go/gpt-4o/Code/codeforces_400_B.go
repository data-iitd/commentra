package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	c := make(map[int]struct{})
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		gIndex := strings.Index(s, "G")
		sIndex := strings.Index(s, "S")
		if gIndex != -1 && sIndex != -1 {
			c[sIndex-gIndex] = struct{}{}
		}
	}

	negativeFound := false
	for a := range c {
		if a < 0 {
			negativeFound = true
			break
		}
	}

	if negativeFound {
		fmt.Println(-1)
	} else {
		fmt.Println(len(c))
	}
}

// <END-OF-CODE>
