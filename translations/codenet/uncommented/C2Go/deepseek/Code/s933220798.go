package main

import (
	"fmt"
)

func main() {
	var a float64
	var ave float64
	var i int
	
	for i = 0; i < 5; i++ {
		fmt.Scan(&a)
		if a <= 40 {
			ave += 40
		} else {
			ave += a
		}
	}
	
	ave /= 5.0
	
	fmt.Printf("%.0f\n", ave)
}

