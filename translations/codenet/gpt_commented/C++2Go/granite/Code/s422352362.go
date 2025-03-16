
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
		sumpre = sumpre + a[i-1]
		pre[i] = sumpre
		// Debugging output for prefix sums (commented out)
		// fmt.Printf("%d++\n", pre[i])
	}
	for i := n - 1; i > 0; i-- {
		sumlast = sumlast + a[i]
		last[i] = sumlast
		// Debugging output for suffix sums (commented out)
		// fmt.Printf("%d+++\n", last[i])
	}
	d := int64(1 << 60)
	for i := 1; i < n; i++ {
		// Debugging output for the difference calculation (commented out)
		// fmt.Printf("%d\n", pre[i]-last[i+1])
		if d > int64(abs(pre[i]-last[i+1])) {
			d = int64(abs(pre[i] - last[i+1]))
		}
	}
	fmt.Println(d)
}

