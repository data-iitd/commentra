
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	br := bufio.NewReader(os.Stdin)
	pw := bufio.NewWriter(os.Stdout)
	f := new(Fast)
	f.sol(br, pw)
	pw.Flush()
}

type Fast struct{}

func (f *Fast) sol(br *bufio.Reader, pw *bufio.Writer) {
	s, _ := br.ReadString('\n')
	s = strings.TrimSpace(s)
	cum := make([]int, len(s)+1)
	cum[0] = cum[len(s)] = 0
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}
	q, _ := strconv.Atoi(strings.TrimSpace(br.ReadLine()))
	for ; q > 0; q-- {
		l, _ := strconv.Atoi(strings.TrimSpace(br.ReadLine()))
		r, _ := strconv.Atoi(strings.TrimSpace(br.ReadLine()))
		pw.WriteString(strconv.Itoa(cum[r-1]-cum[l-2]) + "\n")
	}
}

