
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	targ := []rune(s)
	m := make(map[rune]int)
	for i := 0; i < len(targ); i++ {
		if _, ok := m[targ[i]]; !ok {
			m[targ[i]] = 1
		} else {
			m[targ[i]]++
		}
	}
	ok := true
	for k, v := range m {
		if v != 2 {
			ok = false
			break
		}
	}
	if ok && len(m) == 2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

