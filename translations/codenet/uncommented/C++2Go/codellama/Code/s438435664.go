
package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	sum := 0
	for b := 1; b <= n; b++ {
		cnt := (n + 1) / b
		md := (n + 1) % b
		sum += cnt*int(math.Max(float64(b-k), 0)) + int(math.Max(float64(md-k), 0))
		if k == 0 {
			sum--
		}
	}
	fmt.Println(sum)
}

