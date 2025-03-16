
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	l := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}
	for i := 0; i < n; i++ {
		if l[i]+1 < n && l[i]+2 < n {
			fmt.Println("YES")
			break
		}
	}
	fmt.Println("NO")
}

