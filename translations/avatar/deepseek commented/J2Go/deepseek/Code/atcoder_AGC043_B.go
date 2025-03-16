package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// This method calculates a result based on a given string and character.
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

// This method is responsible for solving the problem by processing the input and outputting the result.
func solve() {
	n := nextInt()
	s := next()
	var sb strings.Builder
	for i := 1; i < n; i++ {
		sb.WriteString(strconv.Itoa(int(s[i]) - int(s[i-1])))
	}
	if n == 2 {
		fmt.Fprintln(out, sb.String()[0])
		return
	}
	s = sb.String()
	if strings.Contains(s, "1") {
		fmt.Fprintln(out, cal(s, '1'))
	} else {
		fmt.Fprintln(out, cal(s, '2')*2)
	}
}

var (
	out = bufio.NewWriter(os.Stdout)
	sc  *bufio.Scanner
)

func nextInt() int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}

func next() string {
	sc.Scan()
	return sc.Text()
}

func main() {
	sc = bufio.NewScanner(bufio.NewReader(os.Stdin))
	sc.Split(bufio.ScanWords)
	defer out.Flush()
	solve()
}

