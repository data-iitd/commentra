
package main

import (
	"fmt"
	"math"
)

func main() {
	var a int
	fmt.Scan(&a)
	ar := make([]int, a)
	var max, min int
	for i := 0; i < len(ar); i++ {
		fmt.Scan(&ar[i])
	}
	for i := 0; i < len(ar); i++ {
		max = int(math.Max(float64(ar[i]-ar[0]), float64(ar[len(ar)-1]-ar[i])))
		if i == 0 {
			min = ar[i+1] - ar[i]
		} else if i == len(ar)-1 {
			min = ar[i] - ar[i-1]
		} else {
			min = int(math.Min(float64(ar[i]-ar[i-1]), float64(ar[i+1]-ar[i])))
		}
		fmt.Println(min, max)
	}
}

