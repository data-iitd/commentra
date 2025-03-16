package main

import "fmt"

func main() {
	var v [10]int
	var sum int
	var i int

	for i = 0; i < 10; i++ {
		fmt.Scanf("%d", &v[i])
	}

	for i = 0; i < 10; i++ {
		sum += v[i]
	}

	fmt.Println(sum)
}

