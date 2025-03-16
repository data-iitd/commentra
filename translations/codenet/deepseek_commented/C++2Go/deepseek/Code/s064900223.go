package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n) // Step 4: Read the input value for `n`
	p := make([]int, n) // Step 5: Create a slice `p` of size `n`
	for i := 0; i < n; i++ { // Step 6: Read values into the slice `p`
		fmt.Fscan(reader, &p[i])
	}
	ans := 0 // Step 7: Initialize `ans` to 0
	for i := 0; i < n - 1; i++ { // Step 8: Loop through the slice `p`
		if p[i] == i + 1 { // If the current element `p[i]` is equal to `i+1`
			p[i + 1] = p[i] // Set the next element `p[i+1]` to `p[i]`
			ans += 1 // Increment `ans`
		}
	}
	if p[n - 1] == n { // Step 9: Check the last element
		ans += 1 // Increment `ans` if the last element is equal to `n`
	}
	fmt.Println(ans) // Step 10: Output the result
}

