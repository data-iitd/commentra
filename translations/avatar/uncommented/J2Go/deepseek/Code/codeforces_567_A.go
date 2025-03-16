package main

import (
	"fmt"
)

func main() {
	var a int
	fmt.Scan(&a)
	ar := make([]int, a)
	for i := 0; i < a; i++ {
		fmt.Scan(&ar[i])
	}
	for i := 0; i < a; i++ {
		max := 0
		min := 0
		if i == 0 {
			max = ar[a-1] - ar[i]
			min = ar[i+1] - ar[i]
		} else if i == a-1 {
			max = ar[i] - ar[0]
			min = ar[i] - ar[i-1]
		} else {
			if ar[i]-ar[i-1] > ar[i+1]-ar[i] {
				min = ar[i+1] - ar[i]
			} else {
				min = ar[i] - ar[i-1]
			}
			max = ar[i] - ar[0]
			if ar[i]-ar[0] < ar[i]-ar[a-1] {
				max = ar[i] - ar[0]
			} else {
				max = ar[i] - ar[a-1]
			}
		}
		fmt.Println(min, max)
	}
}
