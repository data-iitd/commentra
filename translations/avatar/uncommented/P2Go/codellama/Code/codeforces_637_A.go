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
	s := strings.Split(os.Args[1], " ")
	w := make(map[string]int)
	for _, v := range s {
		w[v]++
	}
	s = s[:len(s)-1]
	c := -1
	a := 0
	for i, v := range w {
		if v == max(w) {
			if strings.Index(s, i) > c {
				a = i
				c = strings.Index(s, i)
			}
		}
	}
	fmt.Println(a)
}

func max(w map[string]int) int {
	max := 0
	for _, v := range w {
		if v > max {
			max = v
		}
	}
	return max
}

// 