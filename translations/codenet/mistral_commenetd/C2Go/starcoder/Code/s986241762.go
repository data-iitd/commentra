
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
	var n int
	var sum int64
<<<<<<< HEAD
	var a [100000]int

	fmt.Println("Enter the number of elements in the array: ")
	fmt.Scanf("%d", &n)

=======
	var a [1000000]int
	fmt.Println("Enter the number of elements in the array: ")
	fmt.Scanf("%d", &n)
>>>>>>> 98c87cb78a (data updated)
	fmt.Println("Enter", n, "integers:")
	for i := 0; i < n; i++ {
		fmt.Println("Enter element number", i+1, ": ")
		fmt.Scanf("%d", &a[i])
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	for i := 1; i < n; i++ {
		if a[i-1] > a[i] {
			sum += int64(a[i-1] - a[i])
			a[i] = a[i-1]
		}
	}
<<<<<<< HEAD

=======
>>>>>>> 98c87cb78a (data updated)
	fmt.Println("The sum of the differences is:", sum)
}

