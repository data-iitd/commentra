package main

import (
	"fmt"
)

// Function to return the minimum of two integers
func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

// Function to process the chain of colors and return the count of remaining colors
func Chain(b []int, n int) int {
	a := make([]int, n)
	copy(a, b)
	
	for i := 0; i < n-4; i++ {
		if a[i] != 0 && a[i] == a[i+1] && a[i] == a[i+2] && a[i] == a[i+3] {
			count := 0
			color := a[i]
			
			for j := i; a[j] == color; j++ {
				a[j] = 0
				count++
			}
			
			for j := 0; i+j+count < n; j++ {
				a[i+j] = a[i+j+count]
				a[i+j+count] = 0
			}
			
			i = 0
		}
	}
	
	count := 0
	for a[count] != 0 {
		count++
	}
	
	if count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3] {
		return 0
	}
	
	return count
}

// Main function to execute the program
func main() {
	for {
		var n int
		fmt.Scan(&n)
		if n == 0 {
			break
		}
		
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		
		ans := n
		for i := 0; i < n-4; i++ {
			count := [3]int{0, 0, 0}
			
			for j := i; j < i+4; j++ {
				if a[j]-1 >= 0 {
					count[a[j]-1]++
				}
			}
			
			color := 0
			for j := 0; j < 3; j++ {
				if count[j] >= 3 {
					color = j + 1
					break
				}
			}
			
			if color != 0 {
				for j := i; j < i+4; j++ {
					buf := a[j]
					a[j] = color
					ans = min(ans, Chain(a, n))
					a[j] = buf
				}
			}
		}
		
		fmt.Println(ans)
	}
}

