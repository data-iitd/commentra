
package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	var arr []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		arr = append(arr, x)
	}
	fmt.Println(sum(arr, k))
}

func sum(arr []int, k int) int {
	var sum int
	for i := 0; i < k; i++ {
		sum += arr[i]
	}
	return sum
}

