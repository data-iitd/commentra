package main

import (
	"fmt"
)

const N = 2000

func main() {
	var num1, num2, a, ans int
	sum := 0
	math := make([]int, N+1)
	math[0] = 1

	fmt.Scan(&num1)
	for i := 0; i < num1; i++ {
		fmt.Scan(&a)
		sum += a
		for j := sum - a; j >= 0; j-- {
			if math[j] == 1 {
				math[j+a] = 1
			}
		}
	}

	fmt.Scan(&num2)
	for i := 0; i < num2; i++ {
		fmt.Scan(&ans)
		if math[ans] == 1 {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

// <END-OF-CODE>
