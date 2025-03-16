
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var VP, VD, T, F, C float64
	var answer int
	var start float64

	VP, _ = strconv.ParseFloat(os.Args[1], 64)
	VD, _ = strconv.ParseFloat(os.Args[2], 64)
	T, _ = strconv.ParseFloat(os.Args[3], 64)
	F, _ = strconv.ParseFloat(os.Args[4], 64)
	C, _ = strconv.ParseFloat(os.Args[5], 64)

	if VD <= VP {
		fmt.Println(0)
		return
	}

	answer = 0
	start = T

	for {
		x := start * VP / (VD - VP)

		if (start + x) * VP >= C {
			break
		}

		start += 2*x + F
		answer++
	}

	fmt.Println(answer)
}

