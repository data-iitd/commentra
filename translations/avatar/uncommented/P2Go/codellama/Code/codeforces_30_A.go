package main

import "fmt"

func task4(a, b, n int) int {
	for x := -1000; x <= 1000; x++ {
		if a*int(math.Pow(float64(x), float64(n))) == b {
			return x
		}
	}
	return -1
}

func main() {
	var a, b, n int
	fmt.Scan(&a, &b, &n)
	fmt.Println(task4(a, b, n))
}

