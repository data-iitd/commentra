package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements
	var n int
	fmt.Scanf("%d", &n)

	// Initialize arrays to store the input values
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read the elements of array a
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &a[i])
	}

	// Read the elements of array b
	for i := 1; i <= n; i++ {
		fmt.Scanf("%d", &b[i])
	}

	// Count the occurrences of each element in array b
	for i := 1; i <= n; i++ {
		num[b[i]]++
	}

	// Initialize variables to store the result
	var ss string
	var ans int
	st := make([]bool, n+1)

	// Iterate through the elements of array a
	for i := 1; i <= n; i++ {
		if a[i] == 1 {
			// Mark the current element as visited
			st[i] = true

			// Build the sequence of indices
			var sb strings.Builder
			x := b[i]
			var sss strings.Builder
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(" ")
			sb.WriteString(sss.String()[::-1])
			s := 1

			// Continue building the sequence until a visited element or mismatch is found
			for!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1 {
				sss.Reset()
				sss.WriteString(strconv.Itoa(x))
				sb.WriteString(" ")
				sb.WriteString(sss.String()[::-1])
				st[x] = true
				x = b[x]
				s++
			}

			// Update the result if a longer sequence is found
			if s > ans {
				ans = s
				ss = sb.String()[::-1]
			}
		}
	}

	// Print the result
	fmt.Println(ans)
	fmt.Println(ss)
}

