
package main

import "fmt"

func main() {
	var y int
	fmt.Scan(&y)
	arr := make([]int, y)
	for i := 0; i < y; i++ {
		fmt.Scan(&arr[i])
	}
	for i := 0; i < y; i++ {
		for j := 0; j < y; j++ {
			if i == j {
				continue
			}
			for k := 0; k < y; k++ {
				if arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i]+arr[j] {
					fmt.Println(k+1, j+1, i+1)
					return
				}
			}
		}
	}
	fmt.Println(-1)
}

