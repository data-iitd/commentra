
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
	fmt.Fscanf(in, "%d\n", &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(in, "%d", &a[i])
	}
	pre := int(^uint(0) >> 1)
	ans := 0
	for j := n - 1; j >= 0; j-- {
		ans += int(math.Max(float64(0), math.Min(float64(pre-1), float64(a[j]))))
		pre = int(math.Max(float64(0), math.Min(float64(pre-1), float64(a[j]))))
	}
	fmt.Fprintf(out, "%d\n", ans)
	out.Flush()
}
