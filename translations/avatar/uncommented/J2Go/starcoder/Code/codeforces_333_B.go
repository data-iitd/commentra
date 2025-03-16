package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n, &m)

	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)

	for i := 0; i < m; i++ {
		r, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		c, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}

	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)
	if n%2!= 0 {
		mid := (n + 1) / 2
		if!bannedRows[mid] &&!bannedCols[mid] {
			answer--
		}
	}

	fmt.Fprintln(out, answer)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

