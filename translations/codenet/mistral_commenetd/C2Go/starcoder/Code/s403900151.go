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
	var n, r, p, c int
	var i, j, k, l int
	var a [51]int
	var b [51]int

	// An infinite loop until the user inputs 0 for both n and r
	for {
		fmt.Scanf("%d %d ", &n, &r)
		if n == 0 && r == 0 {
			break
		}

		// Initialize array a with values from 1 to n
		for i = 0; i < n; i++ {
			a[i] = i + 1
		}

		// Iterate r times
		for i = 0; i < r; i++ {
			fmt.Scanf("%d %d ", &p, &c)

			// Initialize array b with elements from array a
			for j = 0; j < c; j++ {
				b[j] = a[n-p-c+1+j]
			}

			// Shift elements of array a to the left by p-1 positions
			for j = 0; j < p-1; j++ {
				a[n-p+j+1] = a[n-p+j]
			}

			// Copy elements from array b to the end of array a
			for j, k = n-p-c+1, 0; k < c; j, k = j+1, k+1 {
				a[j] = b[k]
			}

			// Print the last element of array a
			fmt.Printf("%d\n", a[n-1])
		}
	}
}

