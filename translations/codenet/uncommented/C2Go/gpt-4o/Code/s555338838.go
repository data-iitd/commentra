package main

import (
	"fmt"
)

func main() {
	var len int
	fmt.Scan(&len)
	a := make([]int, len)

	for i := 0; i < len; i++ {
		fmt.Scan(&a[i])
	}

	for j := 1; j < len; j++ {
		for i := 0; i < len; i++ {
			if i != 0 {
				fmt.Printf(" %d", a[i])
			} else {
				fmt.Printf("%d", a[i])
			}
		}
		fmt.Println()

		key := a[j]
		i := j - 1
		for i >= 0 && a[i] > key {
			a[i+1] = a[i]
			i--
		}
		a[i+1] = key
	}

	for i := 0; i < len; i++ {
		if i != 0 {
			fmt.Printf(" %d", a[i])
		} else {
			fmt.Printf("%d", a[i])
		}
	}
	fmt.Println()
}

// <END-OF-CODE>
