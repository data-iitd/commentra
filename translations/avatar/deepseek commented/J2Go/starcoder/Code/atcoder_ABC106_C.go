
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
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	c := []rune(str)
	k, _ := strconv.ParseInt(strings.TrimSpace(reader.ReadString('\n')), 10, 64)
	n := len(c)

	for i := 0; i < int(k); i++ {
		if c[i] == '1' {
			if i == int(k)-1 {
				fmt.Println(1)
				return
			}
		} else {
			fmt.Println(c[i])
			return
		}
	}
}

