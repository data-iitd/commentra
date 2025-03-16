package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	sc := make([]string, 0)
	for _, arg := range os.Args[1:] {
		sc = append(sc, arg)
	}
	q, _ := strconv.Atoi(sc[0])
	for i := 0; i < q; i++ {
		n, _ := strconv.Atoi(sc[i+1])
		x := int(math.Log2(float64(n))) + 1
		s := -1*int(math.Pow(2, float64(x))) + 2 + (n*(n+1))/2 - int(math.Pow(2, float64(x)))
		fmt.Println(s)
	}
}

