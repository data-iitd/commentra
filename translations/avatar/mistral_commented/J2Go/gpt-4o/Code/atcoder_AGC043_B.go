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

	for testCase := 1; testCase <= n; testCase++ {
		num := sc.NextInt()
		s := sc.NextString()

		differences := make([]int, num-1)

		for i := 1; i < num; i++ {
			differences[i-1] = int(math.Abs(float64(s[i]) - float64(s[i-1])))
		}

		if num == 2 {
			fmt.Println(differences[0])
			continue
		}

		sb := strings.Trim(strings.Join(strings.Fields(fmt.Sprint(differences)), ""), "[]")
		if strings.Contains(sb, "1") {
			fmt.Println(cal(sb, '1'))
		} else {
			fmt.Println(cal(sb, '2') * 2)
		}
	}
}

func main() {
	solve()
}

// <END-OF-CODE>
