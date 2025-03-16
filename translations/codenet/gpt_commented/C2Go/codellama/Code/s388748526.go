package main

import (
	"fmt"
	"math"
)

func main() {
	var r float64

	fmt.Print("Enter the radius: ")
	fmt.Scan(&r)

	fmt.Println(r*r*math.Pi, 2*math.Pi*r)
}

