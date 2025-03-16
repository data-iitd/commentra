package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr)) // Reading the number of elements in the array

	left := make(map[int]struct{}) // Using a map to store the indices of elements
	answer := make([]int, n)       // Creating a slice to store the answer for each index

	// Adding all the indices to the map and initializing the answer slice with -1
	for i := 0; i < n; i++ {
		left[i] = struct{}{}
		answer[i] = -1
	}

	qStr, _ := reader.ReadString('\n')
	q, _ := strconv.Atoi(strings.TrimSpace(qStr)) // Reading the number of queries

	// Processing each query
	for i := 0; i < q; i++ {
		queryStr, _ := reader.ReadString('\n')
		query := strings.Fields(queryStr)
		l, _ := strconv.Atoi(query[0])
		r, _ := strconv.Atoi(query[1])
		win, _ := strconv.Atoi(query[2])

		l-- // Adjusting to 0-based index
		r-- // Adjusting to 0-based index

		// Updating the answer for the winning index and all the indices between the left and right indices
		for j := l; j <= r; j++ {
			if _, exists := left[j]; exists {
				answer[j] = win
				delete(left, j)
			}
		}

		// Updating the answer for the winning index in the answer slice
		answer[win-1] = 0

		// Adding the winning index back to the map
		left[win-1] = struct{}{}
	}

	// Printing the answer for each index in the answer slice
	var ans strings.Builder
	for i := 0; i < n; i++ {
		ans.WriteString(fmt.Sprintf("%d", answer[i]))
		if i != n-1 {
			ans.WriteString(" ")
		}
	}

	fmt.Println(ans.String()) // Printing the answer as a single line
}

// <END-OF-CODE>
