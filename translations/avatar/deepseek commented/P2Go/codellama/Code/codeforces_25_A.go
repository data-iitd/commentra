
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&list[i])
	}
	if sum(list) == 1 {
		fmt.Println(index(list, 1))
	} else {
		fmt.Println(index(list, 0))
	}
}

func sum(list []int) int {
	var sum int
	for _, v := range list {
		sum += v
	}
	return sum
}

func index(list []int, v int) int {
	for i, x := range list {
		if x == v {
			return i
		}
	}
	return -1
}

