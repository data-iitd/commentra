
package main

import "fmt"

func main() {
	var n, k, cnt int

	fmt.Scan(&n, &k)
	cnt = 0
	for n > 0 {
		var h int

		fmt.Scan(&h)
		if h >= k {
			cnt++
		}
		n--
	}
	fmt.Println(cnt)
}

