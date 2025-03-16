
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read an integer input n, which defines the range of numbers to permute
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Generate all possible permutations of the numbers from 1 to n
	orig := make([][]int, 0)
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			if i == j {
				continue
			}
			for k := 1; k <= n; k++ {
				if k == i || k == j {
					continue
				}
				for l := 1; l <= n; l++ {
					if l == i || l == j || l == k {
						continue
					}
					orig = append(orig, []int{i, j, k, l})
				}
			}
		}
	}

	// Read the first permutation input as a tuple of integers
	p := make([]int, 0)
	for _, v := range strings.Split(bufio.NewReader(os.Stdin).Scan(), " ") {
		i, _ := strconv.Atoi(v)
		p = append(p, i)
	}

	// Read the second permutation input as a tuple of integers
	q := make([]int, 0)
	for _, v := range strings.Split(bufio.NewReader(os.Stdin).Scan(), " ") {
		i, _ := strconv.Atoi(v)
		q = append(q, i)
	}

	// Find the index of the first permutation in the list of all permutations
	pn := -1
	for i, v := range orig {
		if v[0] == p[0] && v[1] == p[1] && v[2] == p[2] && v[3] == p[3] {
			pn = i
			break
		}
	}

	// Find the index of the second permutation in the list of all permutations
	qn := -1
	for i, v := range orig {
		if v[0] == q[0] && v[1] == q[1] && v[2] == q[2] && v[3] == q[3] {
			qn = i
			break
		}
	}

	// Calculate and print the absolute difference between the two indices
	fmt.Println(int(math.Abs(float64(pn - qn))))
}
