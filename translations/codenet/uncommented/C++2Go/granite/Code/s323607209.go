
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
	var n, k int
	fmt.Fscanf(r, "%d%d\n", &n, &k)
	var l, r int64
	if k%2 == 0 {
		for i := 1; i <= n; i++ {
			if i%k == k/2 {
				l++
			} else if i%k == 0 {
				r++
			}
		}
	} else {
		for i := 1; i <= n; i++ {
			if i%k == 0 {
				r++
			}
		}
	}
	fmt.Fprintf(w, "%d\n", l*l*l+r*r*r)
	w.Flush()
}

