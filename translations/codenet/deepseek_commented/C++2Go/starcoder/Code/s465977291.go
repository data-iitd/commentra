<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var n, d int
	fmt.Scanf("%d %d", &n, &d)
	a := float64(d*2 + 1)
	fmt.Println(int(math.Ceil(float64(n) / a)))
}

