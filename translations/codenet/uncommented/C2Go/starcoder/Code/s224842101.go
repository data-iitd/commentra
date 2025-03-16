package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var i, a, b, s int
	var count [4]int
	for i = 0; i < 4; i++ {
		count[i] = 0
	}
	for i = 0; i < 3; i++ {
		fmt.Scanf("%d %d", &a, &b)
		count[a-1]++
		count[b-1]++
	}
	s = 1
	for i = 0; i < 4; i++ {
		s *= count[i]
	}
	if s == 4 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

