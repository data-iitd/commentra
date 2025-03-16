package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	
	i, req := 1, 1
	
	for k-req >= 0 {
		if k-req >= 0 {
			k -= req
		} else {
			break
		}
		i++
		if i%n != 0 {
			req = i % n
		} else {
			req = n
		}
	}
	
	fmt.Println(k)
}

