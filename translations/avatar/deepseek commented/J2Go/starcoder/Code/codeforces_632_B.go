package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the size of the array")
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	fmt.Println("Enter the elements of the array")
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadString('\n'))
	}
	fmt.Println("Enter the string")
	s := reader.ReadString('\n')
	s = strings.TrimSpace(s)
	sum := 0
	for i := 0; i < len(s); i++ {
		if s[i] == 'B' {
			sum += a[i]
		}
	}
	ans := sum
	sum1 := sum
	for i := 0; i < len(s); i++ {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		ans = max(ans, sum1)
	}
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == 'A' {
			sum1 += a[i]
		} else {
			sum1 -= a[i]
		}
		ans = max(ans, sum1)
	}
	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

