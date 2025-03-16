
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
	fmt.Scan(&n)
	s1 := make([]byte, n)
	str := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s1[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&str[i])
	}
	cnt := 0
	for i := 0; i < n; i++ {
		str[i+n] = s1[i]
		cnt++
	}
	for i := 0; i < n; i++ {
		str[i+n] = str[i]
		cnt++
	}
	f := make([]int, cnt+1)
	f[0] = 0
	f[1] = 0
	j := 0
	for i := 2; i <= cnt; i++ {
		for j > 0 && str[j+1] != str[i] {
			j = f[j]
		}
		if str[j+1] == str[i] {
			j++
		}
		f[i] = j
	}
	len := 0
	if f[cnt] < n {
		len = f[cnt]
	} else if f[cnt] < n+n {
		len = n
	} else {
		len = n + n - f[cnt]
	}
	fmt.Println(2 * n - len)
}

// 