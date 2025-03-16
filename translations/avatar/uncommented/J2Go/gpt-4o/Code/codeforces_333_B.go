package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(in, &n, &m)

	bannedRows := make(map[int]struct{})
	bannedCols := make(map[int]struct{})

	for i := 0; i < m; i++ {
		var r, c int
		fmt.Fscan(in, &r, &c)
		if r > 1 && r < n {
			bannedRows[r] = struct{}{}
		}
		if c > 1 && c < n {
			bannedCols[c] = struct{}{}
		}
	}

	answer := (n - 2) * 2
	answer -= len(bannedRows)
	answer -= len(bannedCols)

	if n%2 != 0 {
		mid := (n + 1) / 2
		if _, ok := bannedRows[mid]; !ok {
			if _, ok := bannedCols[mid]; !ok {
				answer--
			}
		}
	}

	fmt.Println(answer)
}

// <END-OF-CODE>
