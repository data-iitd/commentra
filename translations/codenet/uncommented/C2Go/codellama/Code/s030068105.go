package main

import (
	"fmt"
	"os"
)

func main() {
	var n int
	fmt.Scanln(&n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&data[i])
	}
	max := 0
	index := 0
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}
	a := 0
	for i := 0; i < n; i++ {
		if i != index {
			a += data[i]
		}
	}
	if a > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

