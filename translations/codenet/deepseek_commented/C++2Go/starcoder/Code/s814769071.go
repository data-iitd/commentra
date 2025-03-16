#pragma region
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import "fmt"

func main() {
	// Step 2: Read input values
	var n, k int
	fmt.Scanf("%d %d", &n, &k)

	// Step 3: Calculate the maximum and minimum sums
	mx := n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2
	mn := k * (k - 1) / 2

	// Step 4: Initialize variables
	res := 0

	// Step 5: Loop through possible lengths
	for i := k; i <= n+1; i++ {
		// Update res, mx, and mn in each iteration
		res += mx - mn + 1
		mx += n - i
		mn += i
		res %= 1000000007
	}

	// Step 6: Output the result
	fmt.Println(res)
}

#pragma endregion

