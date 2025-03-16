package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, x, min, m, i int
	fmt.Scanf("%d %d %d", &n, &x, &min)
	x -= min
	for i = 1; i < n; i++ {
		fmt.Scanf("%d", &m)
		x -= m
		if min > m {
			min = m
		}
	}
	fmt.Printf("%d\n", n+x/min)
}

