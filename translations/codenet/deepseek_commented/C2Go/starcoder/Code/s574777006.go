<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, i, j, q, sum int
	var x, y []int
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	fmt.Scanf("%d", &n)
	x = make([]int, n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &x[i])
	}
	fmt.Scanf("%d", &q)
	y = make([]int, q)
	for i = 0; i < q; i++ {
		fmt.Scanf("%d", &y[i])
	}
	for i = 0; i < q; i++ {
		for j = 0; j < n; j++ {
			if y[i] == x[j] {
				sum = sum + 1
				break
			}
		}
	}
	fmt.Printf("%d\n", sum)
}

