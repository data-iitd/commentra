package main

import "fmt"

func main() {
	var n, k, x, y, z int
	fmt.Scan(&n, &k)
	x = n / k
	y = n % k
	if y != 0 {
		z = x + 1 - x
	} else {
		z = x - x
	}
	fmt.Println(z)
}

