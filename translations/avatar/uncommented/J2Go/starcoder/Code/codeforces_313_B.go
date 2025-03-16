package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s string
	fmt.Fscanln(reader, &s)
	cum := make([]int, len(s)+1)
	cum[0], cum[len(s)] = 0, 0
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			cum[i] = cum[i-1] + 1
		} else {
			cum[i] = cum[i-1]
		}
	}

	var q int
	fmt.Fscanln(reader, &q)
	for q > 0 {
		var l, r int
		fmt.Fscanln(reader, &l, &r)
		l, r = l-1, r-1
		fmt.Fprintln(writer, cum[r]-cum[l])
		q--
	}
}

