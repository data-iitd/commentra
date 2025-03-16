<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, x int
	var s string

	fmt.Scanf("%d", &n)

	for i := 1; i <= n; i++ {
		x = i
		s = strconv.Itoa(x)

		if x%3 == 0 || x%10 == 3 {
			fmt.Printf(" %d", i)
			continue
		} else {
			k := len(s)

			for k > 0 {
				k--
				j := int(math.Pow(10, float64(k)))

				if (x/j)%10 == 3 {
					fmt.Printf(" %d", i)
					break
				}
			}
		}
	}
	fmt.Println()
}

