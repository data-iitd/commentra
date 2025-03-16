package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	s, _ := reader.ReadString('\n')
	targ := strings.Split(s, "")
	m := make(map[string]int)
	for _, v := range targ {
		if _, ok := m[v]; ok {
			m[v] += 1
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

