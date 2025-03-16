package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)
	bstr := strconv.Itoa(b)
	num := a*int(math.Pow10(len(bstr))) + b

	var i int
	for i = 1; i <= 100100; i++ {
		if i*i == num {
			break
		}
	}

	if i > 100100 {
		fmt.Println("No")
	} else {
		fmt.Println("Yes")
	}
}

