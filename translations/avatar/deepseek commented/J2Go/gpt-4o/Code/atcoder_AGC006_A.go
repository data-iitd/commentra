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

// Computes the failure array for the given pattern
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

	// Read input values
	var n int
	fmt.Fscan(reader, &n)
	s1, _ := reader.ReadString('\n')
	s1 = strings.TrimSpace(s1)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)

	// Construct a combined string
	cnt := 0
	for _, char := range str {
		cnt++
		b[cnt] = char
	}
	for _, char := range s1 {
		cnt++
		b[cnt] = char
	}

	// Compute the failure array for the combined string
	getFail(b[:], cnt)

	// Calculate the result based on the failure array
	len := min(f[cnt], min(n, n))

	// Print the result
	fmt.Fprintln(writer, 2*n-len)
	writer.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
