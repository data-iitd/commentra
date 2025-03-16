
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func readInt() int {
	sum := 0
	for {
		c, err := reader.ReadByte()
		if err!= nil {
			panic(err)
		}
		if c =='' || c == '\n' {
			break
		}
		sum = sum*10 + int(c-'0')
	}
	return sum
}

func main() {
	q := readInt()
	for q > 0 {
		q--
		n := readInt()
		x := int(float64(n) / float64(2))
		x++
		s := -1*(1<<uint(x)) + 2 + int64(n)*(int64(n)+1)/2 - (1 << uint(x))
		fmt.Println(s)
	}
}

