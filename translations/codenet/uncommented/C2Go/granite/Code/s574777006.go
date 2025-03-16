
package main

import "fmt"

func main() {
	
	var n, i, j, q, x, y, sum int
	
	fmt.Scan(&n)
	
	for i = 0; i < n; i++ {
		fmt.Scan(&x)
	}
	
	fmt.Scan(&q)
	
	for i = 0; i < q; i++ {
		fmt.Scan(&y)
	}
	
	for i = 0; i < q; i++ {
		for j = 0; j < n; j++ {
			if y == x {
				sum = sum + 1
				break
			}
		}
	}
	
	fmt.Println(sum)
	
	//