package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Main struct{}

func (m *Main) cal(s string, c byte) int {
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

func (m *Main) solve() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	s := sc.Text()

	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteByte(byte(math.Abs(float64(s[i]) - float64(s[i-1]))))
	}

	if n == 2 {
		fmt.Println(sb.String()[0])
		return
	}

	s = sb.String()
	if strings.Contains(s, "1") {
		fmt.Println(m.cal(s, '1'))
	} else {
		fmt.Println(m.cal(s, '2') * 2)
	}
}

func main() {
	m := Main{}
	m.solve()
}

// <END-OF-CODE>
