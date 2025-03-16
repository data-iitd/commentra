package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k, l, c int
	var a int

	n, _ = strconv.Atoi(os.Args[1])
	k, _ = strconv.Atoi(os.Args[2])
	l = 0
	c = 1

	for i := 0; i < n; i++ {
		a, _ = strconv.Atoi(os.Args[i+3])

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

