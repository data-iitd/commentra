
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, k := getInput()
	v := getInput()
	d := []string{"LEFT", "RIGHT"}
	f := k-1 < n-k
	m := min(k-1, n-k)
	a := make([]string, 0)
	for i := 0; i < m; i++ {
		a = append(a, d[not f])
	}
	for i := len(v) - 1; i >= 0; i -= 2 * f {
		a = append(a, "PRINT "+v[i])
		a = append(a, d[f])
	}
	fmt.Println(strings.Join(a[:len(a)-1], "\n"))
}

func getInput() (int, int) {
	var n, k int
	fmt.Sscanf(strings.Join(os.Args[1:], " "), "%d %d", &n, &k)
	return n, k
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func not(a bool) bool {
	return!a
}

