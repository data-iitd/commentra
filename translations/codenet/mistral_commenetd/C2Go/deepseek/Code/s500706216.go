package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read input n and k
	var n, k int
	fmt.Scan(&n, &k)

	// Read input array a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Initialize light array based on initial a array
	light := make([]int, n+1)
	for i := 0; i < n; i++ {
		r := i - a[i]
		l := i + a[i]
		if r < 0 {
			r = 0
		}
		if l+1 > n {
			l = n + 1
		}
		light[r]++
		light[l]--
	}

	// Perform k iterations
	for i := 0; i < k; i++ {
		// Initialize temporary array tmpa
		tmpa := make([]int, n)
		sum := 0
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}

		// Update light array based on new a array
		for j := 0; j < n; j++ {
			r := j - a[j]
			l := j + a[j]
			if r < 0 {
				r = 0
			}
			if l+1 > n {
				l = n + 1
			}
			light[r]--
			light[l]++
		}

		// Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j] != a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
	}

	// Print out updated a array
	for j := 0; j < n; j++ {
		fmt.Print(a[j])
		if j < n-1 {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}

