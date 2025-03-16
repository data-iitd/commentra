
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	arr := make([]int, n)
	gen := make([]int, 11)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		gen[arr[i]]++
	}
	ans := 0
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				ans += int(gen[i]) * int(gen[k])
			}
		}
	}
	fmt.Println(ans / 2)
}

