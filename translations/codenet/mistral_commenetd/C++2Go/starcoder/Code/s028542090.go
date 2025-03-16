
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var k int
	var a [100100]int
	var min, max int

	fmt.Scanf("%d", &k)

	for i := 0; i < k; i++ {
		fmt.Scanf("%d", &a[i])
	}

	if a[k-1]!= 2 {
		fmt.Println(-1)
		return
	}

	max = 3
	min = 2

	for i := k - 2; i >= 0; i-- {
		if a[i] > max {
			fmt.Println(-1)
			return
		} else {
			max = ((max / a[i]) + 1) * a[i] - 1
			if min%a[i]!= 0 {
				min = ((min / a[i]) + 1) * a[i]
			}
		}

		if max <= min {
			fmt.Println(-1)
			return
		}
	}

	fmt.Printf("%d %d\n", min, max)
}

