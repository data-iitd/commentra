
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
	sc.Buffer(make([]byte, 1024), int(1e11))

	var n int
	var s string
	var ans int

	n = nextInt(sc)
	s = nextString(sc)

	for i := 1; i < n; i++ {
		ans += abs(int(s[i]) - int(s[i-1]))
	}

	if n == 2 {
		fmt.Println(string(s[0]))
		return
	}

	if strings.Contains(s, "1") {
		fmt.Println(cal(s, '1'))
	} else {
		fmt.Println(cal(s, '2') * 2)
	}
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

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}

func nextString(sc *bufio.Scanner) string {
	sc.Scan()
	return sc.Text()
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 