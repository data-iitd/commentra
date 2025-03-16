
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Define a constant for the value of PI
	const PI = 3.14159265358979

	// Define a type alias for long long
	type ll = int64

	// Macro to simplify loop creation
	rep := func(i, n int) {
		for ; i < n; i++ {
			// Do something
		}
	}

	// Input the number of groups n and m
	var n, m int
	fmt.Fscanf(bufio.NewReader(os.Stdin), "%d %d\n", &n, &m)

	// Initialize the answer variable to store the total pairs
	ans := 0

	// Calculate the number of pairs within group n
	// The formula n*(n-1)/2 gives the number of ways to choose 2 from n
	ans += n * (n - 1) / 2

	// Calculate the number of pairs within group m
	// Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
	ans += m * (m - 1) / 2

	// Output the total number of pairs
	fmt.Println(ans)
}

