
package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(r, "%d\n", &n)
	ans := make([]int, n)
	for i := 0; i < n-1; i++ {
		var a int
		fmt.Fscanf(r, "%d\n", &a)
		a--
		ans[a]++
	}
	for i := 0; i < n; i++ {
		fmt.Fprintf(w, "%d\n", ans[i])
	}
	w.Flush()
}

