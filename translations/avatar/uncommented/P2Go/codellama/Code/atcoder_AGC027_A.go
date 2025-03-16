
package main

import "fmt"

func na() []int {
	var n, x int
	fmt.Scan(&n, &x)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	return a
}

func main() {
	a := na()
	ans := 0
	if a[0] > x {
		fmt.Println(0)
		return
	}
	for _, v := range a {
		if v > x {
			x = 0
			break
		}
		x -= v
		ans++
	}
	if x != 0 {
		ans--
	}
	fmt.Println(ans)
}

