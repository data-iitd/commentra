package main

import (
	"fmt"
	"strings"
)

func main() {
	var str string
	fmt.Scan(&str)

	var max, cnt int
	for _, sc := range str {
		if sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T' {
			cnt++
		} else {
			cnt = 0
		}
		if max < cnt {
			max = cnt
		}
	}

	fmt.Println(max)
}

