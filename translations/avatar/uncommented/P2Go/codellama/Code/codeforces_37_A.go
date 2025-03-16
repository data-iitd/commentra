package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	high := 1
	tower := n
	maximum := 1
	for i := 1; i < n; i++ {
		if l[i] == l[i-1] {
			tower--
			high++
		} else {
			if high > maximum {
				maximum = high
			}
			high = 1
		}
	}
	if high > maximum {
		maximum = high
	}
	fmt.Println(maximum, tower)
}

