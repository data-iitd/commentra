package main

import (
	"fmt"
)

func main() {
	var n int
	var height float64
	var fd [6]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&height)
		if height >= 185.0 {
			fd[5]++
		} else if height >= 180.0 {
			fd[4]++
		} else if height >= 175.0 {
			fd[3]++
		} else if height >= 170.0 {
			fd[2]++
		} else if height >= 165.0 {
			fd[1]++
		} else {
			fd[0]++
		}
	}

	for i := 0; i < 6; i++ {
		fmt.Printf("%d:", i+1)
		for j := 0; j < fd[i]; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}
}

