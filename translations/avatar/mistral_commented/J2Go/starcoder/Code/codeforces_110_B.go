
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		n   int
		i   int
		j   int
		c   []byte
		p   byte = 'a'
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)
	c = make([]byte, n)

	for i = 0; i < 4; i++ {
		for j = i; j < n; j += 4 {
			c[j] = p
			p++
		}
	}

	for i = 0; i < n; i++ {
		fmt.Printf("%c", c[i])
	}
}

