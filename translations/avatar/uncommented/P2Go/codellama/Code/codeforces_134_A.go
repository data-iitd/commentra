package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	x := 0
	for _, v := range w {
		x += v
	}
	d := make([]int, 0)
	for i := 0; i < n; i++ {
		if (x-w[i])/(n-1) == w[i] {
			d = append(d, i+1)
		}
	}
	fmt.Println(len(d))
	fmt.Println(strings.Join(strings.Fields(fmt.Sprint(d)), " "))
}

