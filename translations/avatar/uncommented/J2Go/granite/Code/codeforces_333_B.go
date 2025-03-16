
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
	var n, m int
	fmt.Fscanf(reader, "%d %d\n", &n, &m)
	bannedRows := make(map[int]bool)
	bannedCols := make(map[int]bool)
	for i := 0; i < m; i++ {
		var r, c int
		fmt.Fscanf(reader, "%d %d\n", &r, &c)
		if r > 1 && r < n {
			bannedRows[r] = true
		}
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
	fmt.Println(answer)
}

// 