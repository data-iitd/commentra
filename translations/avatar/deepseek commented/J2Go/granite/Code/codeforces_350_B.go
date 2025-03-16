
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
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Initialize arrays to store the input values
	a := make([]int, n+1)
	b := make([]int, n+1)
	num := make([]int, n+1)

	// Read the elements of array a
	for i := 1; i <= n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
	}

	// Read the elements of array b
	for i := 1; i <= n; i++ {
		b[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
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
			sb := strings.Builder{}
			x := b[i]
			sss := strings.Builder{}
			sss.WriteString(strconv.Itoa(i))
			sb.WriteString(sss.String())
			s := 1

			// Continue building the sequence until a visited element or mismatch is found
			for!st[x] && num[x] == 1 && x!= 0 && a[x]!= 1 {
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

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimRight(string(str), "\r\n")
	}
	return ""
}

