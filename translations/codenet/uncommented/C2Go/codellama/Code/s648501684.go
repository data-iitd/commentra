package main

import "fmt"

func main() {
	var n, k, q int
	fmt.Scan(&n, &k, &q)

	arr := make([]int, n+1)
	for i := 0; i <= n; i++ {
		arr[i] = 0
	}

	for i := 0; i < q; i++ {
		var temp int
		fmt.Scan(&temp)
		arr[temp] += 1
	}

	for i := 1; i <= n; i++ {
		if arr[i] > (q - k) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

