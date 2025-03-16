package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)
	bstr := fmt.Sprintf("%d", b)
	num := a * int(math.Pow(10, float64(len(bstr)))) + b

	for i := 1; i <= 100100; i++ {
		if i*i == num {
			fmt.Println("Yes")
			return
		}
	}
	fmt.Println("No")
}

