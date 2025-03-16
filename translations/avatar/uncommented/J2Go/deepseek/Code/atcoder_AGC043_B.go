package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

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

func solve() {
	var n int
	var s string
	fmt.Scan(&n, &s)
	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(math.Abs(float64(s[i]-s[i-1])))))
	}
	if n == 2 {
		fmt.Println(sb.String()[0])
		return
	}
	s = sb.String()
	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1'))
	} else {
		fmt.Println(cal(s, '2') * 2)
	}
}

func main() {
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	solve()
}

