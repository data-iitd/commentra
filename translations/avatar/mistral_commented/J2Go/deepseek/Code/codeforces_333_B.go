package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var in = bufio.NewScanner(os.Stdin)
var out = bufio.NewWriter(os.Stdout)

func main() {
	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	in.Scan()
	m, _ := strconv.Atoi(in.Text())

	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	for i := 0; i < m; i++ {
		in.Scan()
		parts := strings.Split(in.Text(), " ")
		r, _ := strconv.Atoi(parts[0])
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c, _ := strconv.Atoi(parts[1])
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	if n%2 != 0 {
		mid := (n + 1) / 2
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}

	fmt.Fprintln(out, answer)
	out.Flush()
}

