<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var n int
	var l []int
	var i, j, k, cnt, tmp int
	// Read the number of elements in the array
	fmt.Scanf("%d", &n)
	// Read the elements of the array
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &l[i])
	}
	// Sort the array in ascending order using bubble sort
	for i = 0; i < n-1; i++ {
		for j = i + 1; j < n; j++ {
			if l[j] < l[i] {
				tmp = l[i]
				l[i] = l[j]
				l[j] = tmp
			}
		}
	}
	// Count the number of valid triangles that can be formed
	for i = 0; i < n-2; i++ {
		for j = i + 1; j < n-1; j++ {
			for k = j + 1; k < n; k++ {
				if l[i]+l[j] > l[k] {
					cnt++
				} else {
					break
				}
			}
		}
	}
	// Print the count of valid triangles
	fmt.Printf("%d\n", cnt)
}

