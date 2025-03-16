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
	var (
		a, b, c, i, j, k int
		max               int
	)

	fmt.Print("Enter the number of test cases: ")
	fmt.Scanf("%d", &j)

	for i = 0; i < j; i++ {
		fmt.Print("Enter the values of a, b, and c for test case ", i+1, ": ")
		fmt.Scanf("%d", &a)
		fmt.Scanf("%d", &b)
		fmt.Scanf("%d", &c)

		max = a
		k = 0

		if max <= b {
			max = b
			k = 1
		}

		if max <= c {
			max = c
			k = 2
		}

		max *= max
		a *= a
		b *= b
		c *= c

		if k == 0 && max == b+c {
			fmt.Println("YES")
		} else if k == 1 && max == a+c {
			fmt.Println("YES")
		} else if k == 2 && max == a+b {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

