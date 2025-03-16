
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Ask the user for the size of the permutation list
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).Scan())

	// Create a list of all possible permutations of numbers from 1 to n
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

	// Ask the user for two permutations as tuples
	p := make([]int, 0)
	for _, v := range bufio.NewReader(os.Stdin).Scan().Split(" ") {
		i, _ := strconv.Atoi(v)
		p = append(p, i)
	}
	q := make([]int, 0)
	for _, v := range bufio.NewReader(os.Stdin).Scan().Split(" ") {
		i, _ := strconv.Atoi(v)
		q = append(q, i)
	}

	// Find the indices of p and q in the orig list
	pn := -1
	for i, v := range orig {
		if v[0] == p[0] && v[1] == p[1] && v[2] == p[2] && v[3] == p[3] {
			pn = i
		}
		if v[0] == q[0] && v[1] == q[1] && v[2] == q[2] && v[3] == q[3] {
			qn = i
		}
	}

	// Print the absolute difference between the indices of p and q
	fmt.Println(int(math.Abs(float64(pn - qn))))
}
