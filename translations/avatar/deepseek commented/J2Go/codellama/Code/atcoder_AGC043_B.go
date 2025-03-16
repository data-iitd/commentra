
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)
	sb := ""
	for i := 1; i < n; i++ {
		sb += strconv.Itoa(abs(int(s[i]) - int(s[i-1])))
	}
	if n == 2 {
		fmt.Println(sb[0])
		return
	}
	s = sb
	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1'))
	} else {
		fmt.Println(cal(s, '2') * 2)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func cal(s string, c byte) int {
	n := len(s)
	m := n - 1
	ans := 0
	for i := 0; i < n; i++ {
		if s[i] == c && (m&i) == i {
			ans ^= 1
		}
	}
	return ans
}

// 