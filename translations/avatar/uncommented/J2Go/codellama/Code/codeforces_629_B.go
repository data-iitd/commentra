package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]int, 367)
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		var c string
		var a, b int
		fmt.Scan(&c, &a, &b)
		for j := a; j <= b; j++ {
			if c == "M" {
				sc[j]++
			} else {
				sc[j]--
			}
		}
	}
	var answer int
	for i := 0; i < 367; i++ {
		if sc[i] > answer {
			answer = sc[i]
		}
	}
	fmt.Println(answer * 2)
}

