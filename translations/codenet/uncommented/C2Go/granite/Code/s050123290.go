
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	const N = 1000
	r := bufio.NewReader(os.Stdin)
	su := make([]byte, N)
	var susum int
	for {
		for i := 0; i < N; i++ {
			c, _, err := r.ReadRune()
			if err!= nil {
				fmt.Fprintln(os.Stderr, "Error reading input:", err)
				os.Exit(1)
			}
			su[i] = c
			if c == '\n' {
				break
			}
			susum += int(c - '0')
		}
		if su[0] == '0' {
			break
		}
		fmt.Println(susum)
		susum = 0
	}
}

