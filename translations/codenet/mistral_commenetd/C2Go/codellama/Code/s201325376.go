package main

import "fmt"

func main() {
	var a, b, c, i, count int
	fmt.Scanf("%d%d%d", &a, &b, &c)
	count = 0

	for i = a; i <= b; i++ {
		if c%i == 0 {
			count++
		}
	}

	fmt.Println(count)
}

