package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read the number of elements
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Initialize arrays to store the input values
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read the elements of array a
	for i := 1; i <= n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}

	// Read the elements of array b
	for i := 1; i <= n; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
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
