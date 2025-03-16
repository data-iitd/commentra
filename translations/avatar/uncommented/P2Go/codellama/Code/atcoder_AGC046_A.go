package main

import "fmt"

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var x int
	fmt.Scan(&x)
	fmt.Println(360 / gcd(360, x))
}

