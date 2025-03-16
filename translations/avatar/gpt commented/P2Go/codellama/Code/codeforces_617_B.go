package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var a string
	fmt.Scanln(&a)
	if strings.Count(a, "1") == 0 {
		fmt.Println(0)
	} else {
		var result float64 = 1
		for _, v := range strings.Split(a, "1") {
			result *= float64(strings.Count(v, "0")+1)
		}
		fmt.Println(result)
	}
}

