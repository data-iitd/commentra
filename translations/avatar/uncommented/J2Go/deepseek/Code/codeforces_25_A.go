package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	array := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i])
	}
	odd, even := 0, 0
	oddIndex, evenIndex := 0, 0
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 {
			even++
			evenIndex = i
		} else {
			odd++
			oddIndex = i
		}
	}
	if odd > even {
		fmt.Println(evenIndex)
	} else {
		fmt.Println(oddIndex)
	}
}

