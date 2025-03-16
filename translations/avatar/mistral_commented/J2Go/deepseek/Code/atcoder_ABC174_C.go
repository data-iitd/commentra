package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	br  = bufio.NewReader(os.Stdin)
	pw  = bufio.NewWriter(os.Stdout)
	st  *bufio.Scanner
)

func readInt() int {
	for st == nil || !st.Scan() {
		st = bufio.NewScanner(br)
		st.Split(bufio.ScanWords)
	}
	return parseInt(st.Text())
}

func main() {
	fmt.Fprintln(pw, solve())
	pw.Flush()
}

func solve() int {
	K := readInt()

	if K%2 == 0 || K%5 == 0 {
		return -1
	}

	if K%7 == 0 {
		K /= 7
	}
	K *= 9

	ans, remainder := 1, 10%K

	for remainder != 1 {
		ans++
		remainder = (remainder * 10) % K
	}

	return ans
}

