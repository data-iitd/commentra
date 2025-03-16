package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	t := 0
	for i := 0; i < n; i++ {
		s := 0
		for j := 1; j < n; j++ {
			if j <= i {
				continue
			}
			m := a[i] * a[j]
			s += m
		}
		t += s
	}
	fmt.Printf("%d\n", t)
}

