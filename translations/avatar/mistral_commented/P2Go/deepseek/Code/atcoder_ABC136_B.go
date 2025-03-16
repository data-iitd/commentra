package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	i := 1
	ans := 0

	for math.Pow(10, float64(i)) <= float64(N) {
		ans += int(math.Pow(10, float64(i)) - math.Pow(10, float64(i-1)))
		i += 2
	}

	ans += int(math.Max(0, float64(N-int(math.Pow(10, float64(i-1)))+1)))

	fmt.Println(ans)
}

