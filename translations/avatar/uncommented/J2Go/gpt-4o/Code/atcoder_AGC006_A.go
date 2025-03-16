package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const N = 200 + 10

var f [N]int
var b [N]rune

func getFail(b []rune, m int) {
	j := 0
	f[0] = 0
	f[1] = 0
	for i := 2; i <= m; i++ {
		for j > 0 && b[j+1] != b[i] {
			j = f[j]
		}
		if b[j+1] == b[i] {
			j++
		}
		f[i] = j
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var n int
	fmt.Fscan(reader, &n)
	var s1, str string
	fmt.Fscan(reader, &str, &s1)

	cnt := 0
	for _, char := range str {
		cnt++
		b[cnt] = char
	}
	for _, char := range s1 {
		cnt++
		b[cnt] = char
	}

	getFail(b[:], cnt)

	len := min(f[cnt], min(n, n))
	fmt.Fprintln(writer, 2*n-len)
	writer.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
