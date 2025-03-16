package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const N = 210

var (
	f    [N]int
	b    [N]rune
)

// Computes the failure array for the given pattern
func getFail(b []rune, m int) {
	j := 0
	f[0], f[1] = 0, 0
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
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read input values
	var n int
	var s1, str string
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &s1)
	fmt.Fscan(in, &str)

	// Construct a combined string
	cnt := 0
	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = rune(str[i])
	}
	for i := 0; i < n; i++ {
		cnt++
		b[cnt] = rune(s1[i])
	}

	// Compute the failure array for the combined string
	getFail(b[:cnt+1], cnt)

	// Calculate the result based on the failure array
	len := min(f[cnt], min(n, n))

	// Print the result
	fmt.Fprintln(out, 2*n-len)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

