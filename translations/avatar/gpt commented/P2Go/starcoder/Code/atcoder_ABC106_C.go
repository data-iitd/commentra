
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
	k, _ := strconv.Atoi(reader.ReadString('\n'))
	l := 0
	for i := 0; i < len(s); i++ {
		if s[i]!= '1' {
			break
		}
		l++
	}
	if l >= k {
		fmt.Println(1)
	} else {
		fmt.Println(s[l])
	}
}

