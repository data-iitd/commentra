
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.ParseInt(reader.ReadLine()[2:], 10, 64)
	}
	pre := make([]int64, n)
	last := make([]int64, n)
	sumpre := int64(0)
	sumlast := int64(0)
	for i := 1; i < n; i++ {
		sumpre += a[i-1]
		pre[i] = sumpre
	}
	for i := n - 1; i > 0; i-- {
		sumlast += a[i]
		last[i] = sumlast
	}
	d := int64(1 << 60)
	for i := 1; i < n; i++ {
		if d > abs(pre[i]-last[i+1]) {
			d = abs(pre[i] - last[i+1])
		}
	}
	fmt.Println(d)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

