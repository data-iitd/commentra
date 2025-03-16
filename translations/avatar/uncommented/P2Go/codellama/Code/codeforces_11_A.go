
package main

import "fmt"

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	x := make([]int, n)
	m := 0
	q := 0
	fmt.Scan(&x)
	for i := 0; i < len(x)-1; i++ {
		if x[i] >= x[i+1] {
			q = int((x[i] - x[i+1]) / d + 1)
			m = m + q
			x[i+1] = x[i+1] + q*d
		}
	}
	fmt.Println(m)
}

