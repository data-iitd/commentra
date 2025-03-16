package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i, j, k, a, b, c, max int
	var s string
	var strs []string
	strs = strings.Split(os.Args[1], "\n")
	j, _ = strconv.Atoi(strs[0])
	for i = 0; i < j; i++ {
		s = strs[i+1]
		strs = strings.Split(s, " ")
		a, _ = strconv.Atoi(strs[0])
		b, _ = strconv.Atoi(strs[1])
		c, _ = strconv.Atoi(strs[2])
		max = a
		k = 0
		if max <= b {
			max = b
			k = 1
		}
		if max <= c {
			max = c
			k = 2
		}
		max = max * max
		a = a * a
		b = b * b
		c = c * c
		if k == 0 && max == b+c {
			fmt.Println("YES")
		} else if k == 1 && max == a+c {
			fmt.Println("YES")
		} else if k == 2 && max == a+b {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

