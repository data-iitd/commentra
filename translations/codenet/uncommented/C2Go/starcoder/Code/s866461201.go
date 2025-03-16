package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var height float64
	var fd [6]int
	var i, j int

	fmt.Scanf("%d", &n)
	for n > 0 {
		fmt.Scanf("%f", &height)
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
		n--
	}

	for i = 0; i < 6; i++ {
		fmt.Printf("%d:", i+1)
		for j = 0; j < fd[i]; j++ {
			fmt.Printf("*")
		}
		fmt.Println("")
	}
}

