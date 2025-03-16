
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(r, "%d", &a[i])
	}

	a = a[:compress(a)]
	n = len(a)

	ans := 0
	for i := 1; i < n-1; i++ {
		if (a[i-1] < a[i] && a[i] > a[i+1]) || (a[i-1] > a[i] && a[i] < a[i+1]) {
			ans++
		}
	}

	fmt.Fprintf(w, "%d\n", ans+1)
	w.Flush()
}

func compress(a []int) int {
	n := len(a)
	if n == 0 {
		return 0
	}

	b := make([]int, n)
	b[0] = a[0]
	j := 1
	for i := 1; i < n; i++ {
		if a[i]!= b[j-1] {
			b[j] = a[i]
			j++
		}
	}

	return j
}

