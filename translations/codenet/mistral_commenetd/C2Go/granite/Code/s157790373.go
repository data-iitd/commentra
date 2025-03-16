

package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	LEN = 300
	TRUE  = 1
	FALSE = -1
)

var (
	n int
	A [LEN]int
	flag int
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Fscanf(reader, "%d\n", &n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &A[i])
	}

	var q, M int
	fmt.Fscanf(reader, "%d\n", &q)
	for i := 0; i < q; i++ {
		fmt.Fscanf(reader, "%d\n", &M)
		flag = FALSE
		solve(0, M)
		if flag == TRUE {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}

func solve(i, m int) {
	// Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
	if i > n {
		return
	}

	// Base case: If length'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
	if m < 0 {
		return
	}

	// Base case: If length'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to'm', a subsequence of length'm' can be formed starting from index 'i'
	if m == 0 || m-A[i+1] == 0 {
		flag = TRUE
		return
	}

	// Recursive case: If length'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
	solve(i+1, m)

	// Using the element at index 'i' to form the subsequence of length'm'
	solve(i+1, m-A[i])
}

// 