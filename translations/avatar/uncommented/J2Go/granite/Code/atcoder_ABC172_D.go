
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
	ans := 0
	for i := 1; i < n+1; i++ {
		ans += (int64(n) / int64(i)) * (int64(n) / int64(i)) + 1) / 2
	}
	fmt.Fprintf(w, "%d\n", ans)
	w.Flush()
}

