
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	targ := []rune(s)
	m := make(map[rune]int)
	for _, v := range targ {
		if _, ok := m[v]; ok {
			m[v]++
		} else {
			m[v] = 1
		}
	}
	ok := true
	for _, v := range m {
		if v!= 2 {
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

