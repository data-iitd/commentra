
package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scan(&x)
	fmt.Println(360 / int(math.Gcd(360, float64(x))))
}

