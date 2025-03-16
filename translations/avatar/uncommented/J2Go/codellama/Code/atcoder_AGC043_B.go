
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	var s string
	sc.Scan()
	s = sc.Text()
	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteByte(byte(abs(s[i] - s[i-1])))
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

