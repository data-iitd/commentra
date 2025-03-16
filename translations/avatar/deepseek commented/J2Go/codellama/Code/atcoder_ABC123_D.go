
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	x := make([]int, 3)
	max := 0

	// Step 1: Read input values for the array x and find the maximum value in x.
	for i := 0; i < 3; i++ {
		scanner.Scan()
		x[i] = scanner.Text()
		max = int(math.Max(float64(max), float64(x[i])))
	}

	scanner.Scan()
	k := scanner.Text()
	a := make([][]int, 3)

	// Step 2: Initialize a list of lists to store the input values for each sub-array.
	for i := 0; i < 3; i++ {
		a[i] = make([]int, x[i])
	}

	// Step 3: Read input values for each sub-array, sort them, and store them in the list of lists.
	for i := 0; i < 3; i++ {
		for j := 0; j < x[i]; j++ {
			scanner.Scan()
			a[i][j] = scanner.Text()
		}
		sort.Ints(a[i])
	}

	scanner.Scan()
	k = scanner.Text()
	ans := make([]int, 0)

	// Step 5: Initialize an empty list to store the results.
	// Step 6: Use nested loops to iterate through all possible combinations of elements from the three sub-arrays,
	// and add the sum of the selected elements to the result list if the product of their indices is less than or equal to k.
	for i := 0; i < x[0]; i++ {
		for j := 0; j < x[1]; j++ {
			for m := 0; m < x[2]; m++ {
				if (i+1)*(j+1)*(m+1) <= k {
					tmp := a[0][x[0]-i-1] + a[1][x[1]-j-1] + a[2][x[2]-m-1]
					ans = append(ans, tmp)
				}
			}
		}
	}

	// Step 7: Sort the result list in ascending order.
	sort.Ints(ans)

	n := len(ans)

	// Step 8: Print the top k values from the result list in descending order.
	for i := 0; i < k; i++ {
		fmt.Println(ans[n-i-1])
	}
}

