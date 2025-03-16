<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

func main() {
	var h int64
	fmt.Scanf("%d", &h)
<<<<<<< HEAD
	ans, mx, sum, mn := int64(0), int64(0), int64(0), int64(math.MaxInt64)
=======
	ans := int64(0)
	cnt := int64(1)
>>>>>>> 98c87cb78a (data updated)
	for h!= 1 {
		if h%2!= 0 {
			h--
		}
		h /= 2
<<<<<<< HEAD
		ans += int64(math.Pow(2, float64(cnt)))
		cnt++
=======
		cnt *= 2
		ans += cnt
>>>>>>> 98c87cb78a (data updated)
	}
	fmt.Println(ans + 1)
}

