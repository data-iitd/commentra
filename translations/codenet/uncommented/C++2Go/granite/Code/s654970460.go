
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Print(a[n-1])
	for i := 1; i < n; i++ {
		fmt.Printf(" %d", a[n-i-1])
	}
	fmt.Println()
}

