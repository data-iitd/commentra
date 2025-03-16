package main

import "fmt"

func main() {
	var a float64
	var ave float64 = 0
	var i int

	for i = 0; i < 5; i++ {
		fmt.Scanf("%f", &a)
		if a <= 40 {
			ave += 40
		} else {
			ave += a
		}
	}
	//fmt.Printf("%.0f\n", ave)

	ave /= 5.0

	fmt.Printf("%.0f\n", ave)
}

