package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var source string
	fmt.Scan(&source)

	if len(source) > 10 || len(source) < 1 {
		return
	}

	max_i := int(math.Pow(2, float64(len(source)-1)))

	sum := 0.0

	for i := 0; i < max_i; i++ {
		plus := fmt.Sprintf("%b", i)

		number := 0.0

		working := source
		for plus != "0" {
			i := strings.Index(plus, "1")
			sum += atof(working[:i+1])
			plus = plus[i+1:]
			working = working[i+1:]
		}
		sum += atof(working)
	}

	fmt.Printf("%.0f\n", sum)
}

func atof(s string) float64 {
	f, _ := strconv.ParseFloat(s, 64)
	return f
}

