
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	var (
		n int
		s string
	)
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &s)
		fmt.Printf("%s\n", f(s))
	}
}

func f(s string) string {
	var (
		l   = strings.Split(s, "")
		t   = []string{}
		res string
	)
	for i := 0; i < len(l); i++ {
		t = append(t, l[i])
	}
	for i := 0; i < len(t); i++ {
		res += t[i]
	}
	return res
}

// 