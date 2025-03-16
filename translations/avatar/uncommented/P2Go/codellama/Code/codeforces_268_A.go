
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	q := make([]string, n)
	count := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&q[i])
	}
	for j := 0; j < n; j++ {
		for k := 0; k < n; k++ {
			if q[j] == q[k] {
				continue
			} else if q[j][0] == q[k][len(q[k])-1] {
				count++
			} else {
				continue
			}
		}
	}
	fmt.Println(count)
}

