// Initialize arrays 'maps' and 'num' with given size 'maxn'
var maps [maxn]int
var num [maxn]int

// Main function starts here
func main() {
	// Initialize variable 'n' to read input from standard input
	var n int
	// Start an infinite loop to read multiple test cases
	for {
		// Initialize 'maps' and 'num' arrays with input values
		for i := 1; i <= n; i++ {
			fmt.Scanf("%d", &maps[i])
			num[i] = maps[i] // copy input values to 'num' array
		}
		// Sort 'maps' array in ascending order
		sort.Ints(maps[1:n+1])
		// Calculate the middle index 'm' of sorted 'maps' array
		m := n / 2
		// Process each element in 'num' array based on the middle index 'm'
		for i := 1; i <= n; i++ {
			// If current element 'num[i]' is smaller than or equal to middle element 'maps[m]'
			if num[i] <= maps[m] {
				// Print the next element in sorted 'maps' array
				fmt.Printf("%d\n", maps[m+1])
			}
			// Otherwise print the current middle element 'maps[m]'
			else {
				fmt.Printf("%d\n", maps[m])
			}
		}
	}
	// Return 0 to indicate successful execution of the program
	return 0
}

