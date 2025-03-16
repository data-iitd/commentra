package main

import (
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	var a, b []int
	var cnt int
	var t int

	fmt.Scanf("%d %d", &n, &m)

	a = make([]int, m)
	b = make([]int, m)

	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d", &a[i], &b[i])
	}

	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })

	t = 0
	for i := 0; i < m; i++ {
		if t <= a[i] {
			t = b[i]
			cnt++
		}
	}

	fmt.Printf("%d\n", cnt)
}

