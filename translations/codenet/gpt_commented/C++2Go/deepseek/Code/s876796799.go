package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// Declare an array to hold the input values and an array to store their indices
var a [200000]int
var ind_a [200000]int

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Input the elements into array 'a'
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	for i := 0; i < N; i++ {
		scanner.Scan()
		a[i] = parseInt(scanner.Bytes())
	}

	// Populate 'ind_a' with the indices of the elements in 'a'
	for i := 0; i < N; i++ {
		ind_a[a[i]-1] = i // Store the index of each element based on its value
	}

	// Set to keep track of used indices
	used_inds := make(map[int]bool)
	var ans int64 = 0 // Variable to accumulate the final answer

	// Iterate through each element's index
	for i := 0; i < N; i++ {
		var left_border int = -1 // Variable to store the left border index
		var right_border int = N // Variable to store the right border index
		cur_ind := ind_a[i] // Current index of the element being processed

		// Find the first used index that is not less than cur_ind
		keys := make([]int, 0, len(used_inds))
		for k := range used_inds {
			keys = append(keys, k)
		}
		sort.Ints(keys)
		idx := sort.Search(len(keys), func(i int) bool { return keys[i] >= cur_ind })
		if idx < len(keys) {
			left_border = keys[idx]
		}

		// Find the first used index that is greater than cur_ind
		keys = make([]int, 0, len(used_inds))
		for k := range used_inds {
			keys = append(keys, k)
		}
		sort.Ints(keys)
		idx = sort.Search(len(keys), func(i int) bool { return keys[i] > cur_ind })
		if idx < len(keys) {
			right_border = keys[idx]
		}

		// Calculate the contribution of the current index to the answer
		ans += int64(cur_ind-left_border) * int64(right_border-cur_ind) * int64(i+1)

		// Uncomment the lines below for debugging purposes
		// fmt.Println(i, left_border, right_border)
		// fmt.Println(ans)

		// Insert the current index into the set of used indices
		used_inds[cur_ind] = true
	}

	// Output the final answer
	fmt.Println(ans)
}

func parseInt(b []byte) int {
    neg := false
    if b[0] == '-' {
        neg = true
        b = b[1:]
    }
    x := 0
    for len(b) > 0 {
        x = x*10 + int(b[0]-'0')
        b = b[1:]
    }
    if neg {
        return -x
    }
    return x
}

