
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Taking two inputs from the user, splitting them, and converting them into integers
	v1, v2 := strings.Split(input(), " ")
	v1, _ = strconv.Atoi(v1)
	v2, _ = strconv.Atoi(v2)
	t, _ := strconv.Atoi(input())
	d, _ := strconv.Atoi(input())

	// Initializing variables
	a := 1
	v := v1
	distance := 0

	// Entering a loop that runs `t` times
	for i := 0; i < t; i++ {
		// Checking if the current speed `v` minus `v2` is greater than `(t - i - 1) * d`
		if v-v2 > (t-i-1)*d {
			a *= -1
			v = (t-i-1)*d + v2
		}
		// Adding the current speed `v` to `distance`
		distance += v
		// Updating the speed by adding `a * d` to it
		v += a * d
	}

	// Printing the total `distance`
	fmt.Println(distance)
}

// 