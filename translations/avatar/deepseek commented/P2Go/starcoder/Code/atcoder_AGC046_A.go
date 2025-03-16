
package main

import (
	"fmt"
	"math"
)

func main() {
	var x int
	fmt.Scanf("%d", &x)
	fmt.Println(int(math.Mod(360, float64(x))))
}

