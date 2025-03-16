package main

import (
	"fmt"
)

func B() {
	var x, sum int64
	fmt.Scan(&x)
	sum = 100
	i := 0
	for sum < x {
		sum += sum / 100
		i++
	}
	fmt.Println(i)
}

func main() {
	B()
}

// <END-OF-CODE>
