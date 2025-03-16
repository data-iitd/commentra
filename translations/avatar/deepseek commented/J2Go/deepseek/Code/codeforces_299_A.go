package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Read the input value n, which represents the number of elements in the array.
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	
	// Step 2: Create an array 'a' of size n and read n elements from the input.
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	
	// Step 3: Sort the array 'a'.
	sort.Ints(a)
	
	// Step 4: Find the minimum element in the sorted array 'a'.
	min := a[0]
	
	// Step 5: Check if all elements in the array are divisible by the minimum element. If not, print -1 and exit.
	for _, value := range a {
		if value % min != 0 {
			fmt.Println(-1)
			return
		}
	}
	
	// Step 6: If all elements are divisible, print the minimum element.
	fmt.Println(min)
}

