
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, levels int
	var sum, sum2, sum3 int
	var arr [1000]int
	var count int
	var level2, level3 int
	var arr2 [2000]int
	var arr3 [1000]int
	var j int

	fmt.Scan(&n, &levels)
	for i := 0; i < levels; i++ {
		fmt.Scan(&arr[i])
	}
	fmt.Scan(&level2)
	level3 = levels + level2
	for i := 0; i < level3; i++ {
		fmt.Scan(&arr2[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&arr3[i])
	}
	for i := 0; i < n; i++ {
		for x := 0; x < level3; x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

