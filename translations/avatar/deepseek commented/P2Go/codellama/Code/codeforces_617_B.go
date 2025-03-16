
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	// Take an input from the user and store it in variable 'a'
	fmt.Scanln()
	var a string
	fmt.Scanln(&a)

	// Print the result based on the input
	var count int
	for _, v := range a {
		if v == '1' {
			count++
		}
	}
	if count == 0 {
		fmt.Println(0)
	} else {
		var result float64 = 1
		for _, v := range strings.Split(strings.TrimLeft(a, "0"), "1") {
			result *= float64(len(v)+1)
		}
		fmt.Println(result)
	}
}

