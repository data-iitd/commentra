
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)
	for i := 0; i < m; i++ {
		var r, c int
		fmt.Scan(&r, &c)
		if r > 1 && r < n {
			bannedRows[r] = true
		}
		if c > 1 && c < n {
			bannedCols[c] = true
		}
	}
	answer := (n-2)*2 - len(bannedRows) - len(bannedCols)
	if n%2 != 0 {
		mid := (n + 1) / 2
		if !bannedRows[mid] && !bannedCols[mid] {
			answer--
		}
	}
	fmt.Println(answer)
}

