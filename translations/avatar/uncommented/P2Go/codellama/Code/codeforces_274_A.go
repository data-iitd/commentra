
package main

import "fmt"

func main() {
	var num, k int
	fmt.Scan(&num, &k)
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}
	different := make(map[int]bool)
	temp := 0
	for i := 0; i < num; i++ {
		if arr[i]%k != 0 || !different[arr[i]/k] {
			different[arr[i]] = true
		}
		temp = max(len(different), temp)
	}
	fmt.Println(temp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

