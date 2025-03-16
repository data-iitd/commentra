<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var x, y int
	fmt.Scanf("%d %d", &x, &y)
	if math.Abs(float64(x-y)) <= 1 {
		fmt.Println("Brown")
	} else {
		fmt.Println("Alice")
	}
}

