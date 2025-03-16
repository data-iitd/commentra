package main

import (
	"fmt"
)

func main() {
	var n int

	fmt.Print("Enter the number of integers: ")
	fmt.Scan(&n)

	cnt4, cnt2 := 0, 0

	for i := 0; i < n; i++ {
		var wk int

		fmt.Print("Enter an integer: ")
		fmt.Scan(&wk)

		if wk%4 == 0 {
			cnt4++
		} else if wk%2 == 0 {
			cnt2++
		}
	}

	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

