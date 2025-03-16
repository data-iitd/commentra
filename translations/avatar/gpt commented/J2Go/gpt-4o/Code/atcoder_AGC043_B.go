package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type MyScanner struct {
	scanner *bufio.Scanner
}

func NewMyScanner() *MyScanner {
	return &MyScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (ms *MyScanner) Next() string {
	ms.scanner.Scan()
	return ms.scanner.Text()
}

func (ms *MyScanner) NextInt() int {
	val, _ := strconv.Atoi(ms.Next())
	return val
}

func (ms *MyScanner) NextString() string {
	return ms.Next()
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

func solve() {
	sc := NewMyScanner()
	n := sc.NextInt()
	s := sc.NextString()
	sb := strings.Builder{}

	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(math.Abs(float64(s[i]-s[i-1])))))
	}

	if n == 2 {
		fmt.Println(sb.String()[0:1])
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
	solve()
}

// <END-OF-CODE>
