
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var n int
	fmt.Fscanf(in, "%d\n", &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	max := int64(0)
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if a[j]-a[i] > max {
				max = a[j] - a[i]
			}
		}
	}
	fmt.Fprintf(out, "%d\n", max)
	out.Flush()
}

