package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	s := make(map[string]int)
	l := make([]string, n)
	f := "Yes"
	i := -1
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &l[i])
		s[l[i]]++
		if s[l[i]] >= 2 {
			f = "No"
		}
		if i!= -1 && l[i][len(l[i])-1]!= l[i-1][0] {
			f = "No"
		}
	}
	fmt.Println(f)
}

