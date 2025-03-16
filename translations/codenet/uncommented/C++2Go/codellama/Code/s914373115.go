package main

import (
	"fmt"
)

func main() {
	B()
}

func B() {
	var x int64
	var sum int64
	var i int
	fmt.Scan(&x)
	sum = 100
	for sum < x {
		sum += sum / 100
		i++
	}
	fmt.Println(i)
}

