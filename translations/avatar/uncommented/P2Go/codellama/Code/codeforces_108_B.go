package main

import (
	"fmt"
	"sort"
	"strings"
)

func s() string {
	var a []int
	fmt.Scanln()
	fmt.Scanln()
	a = strings.Split(fmt.Sscanln(), " ")
	sort.Ints(a)
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] && a[i] < a[i-1]*2 {
			return "YES"
		}
	}
	return "NO"
}

func main() {
	fmt.Println(s())
}

