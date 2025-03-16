
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	var a, b, c string
	fmt.Fscanf(in, "%d\n", &n)
	fmt.Fscanf(in, "%s\n", &a)
	fmt.Fscanf(in, "%s\n", &b)
	fmt.Fscanf(in, "%s\n", &c)

	ans := 0
	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}

