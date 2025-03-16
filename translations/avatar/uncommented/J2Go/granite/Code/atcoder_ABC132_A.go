
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	s, _ := in.ReadString('\n')
	targ := strings.Split(s, "")
	m := make(map[string]int)
	for _, v := range targ {
		m[v]++
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

