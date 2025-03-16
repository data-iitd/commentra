package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	source := ""
	fmt.Scanf("%s", &source)

	if len(source) > 10 || len(source) < 1 {
		return
	}

	max_i := int(math.Pow(2, float64(len(source)-1)))

	sum := 0.0

	for i := 0; i < max_i; i++ {
		plus := strconv.FormatInt(int64(i), 2)
		number := 0.0
		working := source
		for plus!= "" {
			i, _ := strconv.Atoi(plus[0:1])
			sum += atof(working[0:i+1])
			plus = plus[i+1:]
			working = working[i+1:]
		}
		sum += atof(working)
	}

	fmt.Printf("%.0f\n", sum)
}

