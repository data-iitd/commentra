
package main

import "fmt"

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
	}
	result := 0
	a := 0
	for i := 1; i < n; i++ {
		a = nums[i-1] - nums[i]
		if a >= 0 {
			result += a / d + 1
			nums[i] += (a / d + 1) * d
		}
	}
	fmt.Println(result)
}

