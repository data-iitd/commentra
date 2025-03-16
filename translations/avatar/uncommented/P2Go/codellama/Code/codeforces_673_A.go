
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	if arr[0] > 15 {
		fmt.Println(15)
	} else {
		for i := 1; i < len(arr); i++ {
			if arr[i]-arr[i-1] > 15 {
				fmt.Println(arr[i-1] + 15)
				break
			}
		}
		if arr[len(arr)-1] == 90 || arr[len(arr)-1]+15 >= 90 {
			fmt.Println(90)
		} else {
			fmt.Println(arr[len(arr)-1] + 15)
		}
	}
}

