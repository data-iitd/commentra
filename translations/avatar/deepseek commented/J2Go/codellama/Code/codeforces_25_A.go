package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	array := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&array[i])
	}
	odd := 0
	even := 0
	odd_ind := 0
	even_ind := 0
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 {
			even++
			even_ind = i
		} else {
			odd++
			odd_ind = i
		}
	}
	if odd > even {
		fmt.Println(even_ind)
	} else {
		fmt.Println(odd_ind)
	}
}

