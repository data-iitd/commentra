
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
	for _, x := range arr {
		if x%k != 0 || !different[x/k] {
			different[x] = true
		}
		temp = max(temp, len(different))
	}
	fmt.Println(temp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

