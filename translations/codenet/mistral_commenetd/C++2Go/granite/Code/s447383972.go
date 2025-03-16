
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Reading input
	reader := bufio.NewReader(os.Stdin)
	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	// Reading array 'a'
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	// Sorting array 'a' in ascending order
	sort.Ints(a)

	// Finding duplicate elements and storing them in 'q'
	q := make([]int, 0)
	for i := 0; i < n-1; i++ {
		if a[i] == a[i+1] {
			q = append(q, a[i])
			i++
		}
	}

	// Outputting the result
	fmt.Println(q[len(q)-1] * q[len(q)-2])
}

