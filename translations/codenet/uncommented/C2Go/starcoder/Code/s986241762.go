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
	sum := 0
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			sum += a[i-1] - a[i]
			a[i] = a[i-1]
		}
	}
	fmt.Printf("%d\n", sum)
}

