package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var v1, v2, t, d int
	input1 := ""
	input2 := ""

	fmt.Scanln(&input1)
	fmt.Scanln(&input2)

	parts1 := strings.Split(input1, " ")
	parts2 := strings.Split(input2, " ")

	v1, _ = strconv.Atoi(parts1[0])
	v2, _ = strconv.Atoi(parts1[1])
	t, _ = strconv.Atoi(parts2[0])
	d, _ = strconv.Atoi(parts2[1])

	a := 1
	v := v1
	distance := 0

	for i := 0; i < t; i++ {
		if v-v2 > (t-i-1)*d {
			a *= -1
			v = (t - i - 1) * d + v2
		}
		distance += v
		v += a * d
	}

	fmt.Println(distance)
}

// <END-OF-CODE>
