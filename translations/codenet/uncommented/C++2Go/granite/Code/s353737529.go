
/*
これを入れて実行
go run code.go
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	rw = bufio.NewReadWriter(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
	sp = bufio.Split(rw, []byte("\n"))
)

func main() {
	var n int
	fmt.Fscanf(rw, "%d\n", &n)

	if n == 0 {
		fmt.Fprintln(rw, "0")
		rw.Flush()
		return
	}

	s := ""

	i := 1
	for n!= 0 {
		if n%2 == 0 {
			s += "0"
		} else {
			s += "1"
		}

		n -= abs(n%2)

		n /= -2
	}

	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}

	fmt.Fprintln(rw, s)
	rw.Flush()
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

