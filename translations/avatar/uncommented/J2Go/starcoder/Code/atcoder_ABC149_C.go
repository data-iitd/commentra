package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)
	if x!= 2 && x%2 == 0 {
		x++
	}
	for {
		var i int
		sqrtNum := math.Sqrt(float64(x))
		for i = 3; i <= int(sqrtNum); i += 2 {
			if x%i == 0 {
				break
			}
		}
		if i > int(sqrtNum) {
			break
		}
		x += 2
	}
	fmt.Println(x)
}

