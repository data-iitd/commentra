
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	n, m := 0, 0
	var v []int
	var vo, ve, vt []int
	var ans int
	var currentElement int

	// Reading the number of elements 'n' from the standard input stream
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())

	// Allocating memory for the integer array 'v' of size 100010
	v = make([]int, n)

	// Reading the elements of the array 'v' from the standard input stream
	for i := 0; i < n; i++ {
		sc.Scan()
		v[i], _ = strconv.Atoi(sc.Text())
	}

	// Initializing all the elements of the arrays 'vo','ve', and 'vt' to zero
	vo = make([]int, 100010)
	ve = make([]int, 100010)
	vt = make([]int, 100010)
	for i := 0; i < 100010; i++ {
		vo[i] = 0
		ve[i] = 0
		vt[i] = 0
	}

	// Counting the occurrences of each unique value in the odd indexed elements of the array 'v' and updating the 'vo' array accordingly
	for i := 0; i < n; i += 2 {
		currentElement = v[i]
		vo[currentElement]++
	}

	// Counting the occurrences of each unique value in the even indexed elements of the array 'v' and updating the've' array accordingly
	for i := 1; i < n; i += 2 {
		currentElement = v[i]
		ve[currentElement]++
	}

	// Sorting the arrays 'vo','ve', and 'vt' in descending order
	sort.Slice(vo, func(i, j int) bool { return vo[i] > vo[j] })
	sort.Slice(ve, func(i, j int) bool { return ve[i] > ve[j] })
	sort.Slice(vt, func(i, j int) bool { return vt[i] > vt[j] })

	// Checking if the sum of the first elements of the arrays 'vo' and've' is equal to the first element of the array 'vt'
	if vo[0]+ve[0] == vt[0] {
		// Calculating the answer as the minimum of the difference between the total number of elements and the sum of the counts of the first elements of the arrays 'vo' and've'
		ans = min(n-vo[0]-ve[1], n-vo[1]-ve[0])
	} else {
		// Calculating the answer as the difference between the count of the first element of the array 'vo' and the count of the first element of the array've'
		ans = n - vo[0] - ve[0]
	}

	// Printing the answer to the standard output stream
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

