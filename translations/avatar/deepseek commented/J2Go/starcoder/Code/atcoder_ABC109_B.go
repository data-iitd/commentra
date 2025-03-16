package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d\n", &N)

	m := make(map[int]string)
	for i := 0; i < N; i++ {
		var s string
		fmt.Scanf("%s\n", &s)
		m[i] = s
	}

	ans := true
	past := make(map[int]string)
	next := ""

	for i := 0; i < N; i++ {
		if past[m[i]]!= "" {
			ans = false
			break
		}
		past[m[i]] = m[i]

		if i!= 0 {
			if next!= m[i][0:1] {
				ans = false
				break
			}
		}
		next = m[i][len(m[i])-1:]
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

