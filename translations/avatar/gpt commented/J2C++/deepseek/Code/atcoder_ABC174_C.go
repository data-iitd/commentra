package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	br  = bufio.NewReader(os.Stdin)
	pw  = bufio.NewWriter(os.Stdout)
	st  []string
	idx int
)

func readInt() int {
	for idx >= len(st) || st[idx] == "" {
		line, _ := br.ReadString('\n')
		st = strings.Split(line, " ")
		idx = 0
	}
	num, _ := strconv.Atoi(st[idx])
	idx++
	return num
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

	ans := 1
	remainder := 10 % K

	for remainder != 1 {
		ans++
		remainder = (remainder * 10) % K
	}

	return ans
}
