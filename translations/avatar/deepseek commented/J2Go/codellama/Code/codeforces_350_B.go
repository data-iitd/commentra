package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	n, _ := strconv.Atoi(os.Args[1])

	// Initialize arrays to store the input values
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read the elements of array a
	for i := 1; i <= n; i++ {
		a[i], _ = strconv.Atoi(os.Args[i+1])
	}

	// Read the elements of array b
	for i := 1; i <= n; i++ {
		b[i], _ = strconv.Atoi(os.Args[i+n+2])
	}

	// Count the occurrences of each element in array b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}

	// Initialize variables to store the result
	ss := ""
	ans := 0
	st := make([]bool, n+1)

	// Iterate through the elements of array a
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			// Mark the current element as visited
			st[i] = true

			// Build the sequence of indices
			sb := strings.Builder{}
			x := b[i]
			sss := strings.Builder{}
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(" " + sss.String())
			s := 1

			// Continue building the sequence until a visited element or mismatch is found
			for !st[x] && num[x] == 1 && x != 0 && a[x] != 1 {
				sss = strings.Builder{}
				sss.WriteString(strconv.Itoa(x))
				sb.WriteString(" " + sss.String())
				st[x] = true
				x = b[x]
				s++
			}

			// Update the result if a longer sequence is found
			if s > ans {
				ans = s
				ss = sb.String()
			}
		}
	}

	// Print the result
	fmt.Println(ans)
	fmt.Println(ss)
}

