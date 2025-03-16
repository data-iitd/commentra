package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	foods := make([]int, m)

	for i := 0; i < n; i++ {
		var k int
		fmt.Scan(&k)

		for j := 0; j < k; j++ {
			var temp int
			fmt.Scan(&temp)
			temp--

			foods[temp]++
		}
	}

	ans := 0

	for _, elem := range foods {
		if elem == n {
			ans++
		}
	}

	fmt.Println(ans)
}

