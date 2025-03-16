package main

import (
	"fmt"
	"strconv"
)

func main() {
	var y int
	fmt.Scan(&y)

	var arr []int
	input, _ := fmt.Scanln()
	inputs := string(input[:])
	for _, i := range inputs.Split(" ") {
		num, _ := strconv.Atoi(i)
		arr = append(arr, num)
	}

	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr); j++ {
			if i == j {
				continue
			}
			for k := 0; k < len(arr); k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i]+arr[j] {
					fmt.Println(k+1, j+1, i+1)
					return
				}
			}
		}
	}
	fmt.Println(-1)
}
