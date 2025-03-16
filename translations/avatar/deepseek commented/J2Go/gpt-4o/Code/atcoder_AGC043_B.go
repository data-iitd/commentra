package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Main struct{}

func (m *Main) cal(s string, c rune) int {
	n := len(s)
	m := n - 1
	ans := 0
	for i, char := range s {
		if char == c && (m&i) == i {
			ans ^= 1
		}
	}
	return ans
}

func (m *Main) solve() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	s := sc.Text()

	sb := make([]rune, 0, n-1)
	for i := 1; i < n; i++ {
		sb = append(sb, rune(abs(int(s[i])-int(s[i-1]))))
	}

	if n == 2 {
		fmt.Println(string(sb[0]))
		return
	}

	s = string(sb)
	if contains(s, '1') {
		fmt.Println(m.cal(s, '1'))
	} else {
		fmt.Println(m.cal(s, '2') * 2)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func contains(s string, c rune) bool {
	for _, char := range s {
		if char == c {
			return true
		}
	}
	return false
}

func main() {
	m := &Main{}
	m.solve()
}

// <END-OF-CODE>
