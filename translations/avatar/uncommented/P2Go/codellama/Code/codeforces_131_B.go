package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	w := make(map[int]int)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		for _, v := range strings.Split(s, " ") {
			x, _ := strconv.Atoi(v)
			w[x]++
		}
	}
	c := 0
	for i, v := range w {
		if i == 0 {
			c += v * (v - 1)
		} else {
			if -i == i {
				c += v * w[-i]
			}
		}
	}
	fmt.Println(c / 2)
}

