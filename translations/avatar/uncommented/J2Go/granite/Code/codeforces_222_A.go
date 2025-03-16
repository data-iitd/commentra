
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(in))
	k, _ := strconv.Atoi(read(in))
	l := 0
	c := 1
	for i := 0; i < n; i++ {
		a, _ := strconv.Atoi(read(in))
		if a == l {
			c += 1
		} else {
			c = 1
		}
		l = a
	}
	if c+k > n {
		fmt.Println(n - c)
	} else {
		fmt.Println(-1)
	}
}

func read(in *bufio.Reader) string {
	str, _ := in.ReadString('\n')
	return str[:len(str)-1]
}

