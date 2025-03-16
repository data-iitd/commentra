package main

import (
	"fmt"
	"strconv"
)

func main() {
	var k, n, w string
	fmt.Scan(&k, &n, &w)
	
	// Convert strings to integers
	kInt, _ := strconv.Atoi(k)
	nInt, _ := strconv.Atoi(n)
	wInt, _ := strconv.Atoi(w)
	
	if 1 <= kInt && kInt <= 1000 && 1 <= wInt && wInt <= 1000 {
		total := 0
		for i := 1; i <= wInt; i++ {
			total += i * kInt
		}
		if total > nInt {
			fmt.Println(total - nInt)
		} else {
			fmt.Println(0)
		}
	}
}

