
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscanf(in, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}
	sort.Ints(a)
	min, max := a[0], a[n-1]
	var minCount, maxCount int64
	for _, v := range a {
		if v == min {
			minCount++
		}
		if v == max {
			maxCount++
		}
	}
	if min == max {
		fmt.Fprintf(out, "%d %d\n", max-min, minCount*(minCount-1)/2)
	} else {
		fmt.Fprintf(out, "%d %d\n", max-min, minCount*maxCount)
	}
}

