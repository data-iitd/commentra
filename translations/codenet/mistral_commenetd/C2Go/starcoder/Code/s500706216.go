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
	// Read input n and k
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n, &k)

	// Read input array a
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	// Initialize light array based on initial a array
	for i := 0; i < n; i++ {
		r, l := i-a[i], i+a[i]
		if r < 0 {
			r = 0
		}
		light[r]++
		if l+1 > n {
			l = n
		}
		light[l+1]--
	}

	// Perform k iterations
	for i := 0; i < k; i++ {
		// Initialize temporary array tmpa
		sum := 0
		for j := 0; j < n; j++ {
			tmpa[j] = a[j]
			sum += light[j]
			a[j] = sum
		}

		// Update light array based on new a array
		for j := 0; j < n; j++ {
			r, l := j-a[j], j+a[j]
			if r < 0 {
				r = 0
			}
			light[r]--
			if l+1 > n {
				l = n
			}
			light[l+1]++
			r, l = j-a[j], j+a[j]
			if r < 0 {
				r = 0
			}
			light[r]++
			if l+1 > n {
				l = n
			}
			light[l+1]--
		}

		// Check if a array is the same for all elements except the first one, and if the first element is equal to the size of the array
		isSame := true
		for j := 0; j < n-1; j++ {
			if a[j]!= a[j+1] {
				isSame = false
				break
			}
		}
		if isSame && a[0] == n {
			break
		}
	}

	// Print out updated a array
	for j := 0; j < n; j++ {
		fmt.Printf("%d", a[j])
		if j == n-1 {
			fmt.Println()
		} else {
			fmt.Print(" ")
		}
	}
}

