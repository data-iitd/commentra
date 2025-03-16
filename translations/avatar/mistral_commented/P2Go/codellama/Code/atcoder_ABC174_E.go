// Function to check if 'k' is positive after checking all elements in 'lis' with mid as divisor
func check(lis []int, k int, mid int) bool {
	// Iterate through each element in the list 'lis'
	for _, i := range lis {
		// If the element 'i' is divisible by 'mid', increment 'k'
		if i%mid == 0 {
			k += 1
		}
		// Subtract the quotient of 'i' and 'mid' from 'k'
		k -= (i / mid)
	}
	// Return True if 'k' is still positive after the loop, else False
	return k >= 0
}

// Take input of 'n' and 'k'
func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Take input of 'n' number of elements in the list 'lis' and store them in a list
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lis[i])
	}

	// Initialize the variables 'a' and 'b' with minimum and maximum values respectively
	a, b := 1, lis[n-1]

	// Initialize the variable 'ans' with the maximum value of 'b'
	ans := b

	// Binary search algorithm to find the answer
	for a <= b {
		// Calculate the middle value of 'a' and 'b'
		mid := (a + b) / 2
		// Check if 'k' is positive after checking all elements in 'lis' with 'mid' as divisor
		if check(lis, k, mid) {
			// Update the answer if the condition is true
			ans = mid
			// Update the upper limit of the binary search 'b'
			b = mid - 1
		} else {
			// Update the lower limit of the binary search 'a'
			a = mid + 1
		}
	}

	// Print the answer
	fmt.Println(ans)
}

