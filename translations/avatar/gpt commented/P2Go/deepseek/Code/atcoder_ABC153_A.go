package main

import (
	"fmt"
	"math"
)

func main() {
	var h, a int
	fmt.Scan(&h, &a)

	sho := int(math.Ceil(float64(h) / float64(a)))
	am := h % a

	if am != 0 {
		sho += 1
	}

	fmt.Println(sho)
}

