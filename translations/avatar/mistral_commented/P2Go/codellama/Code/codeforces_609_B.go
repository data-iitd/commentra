// Function to read input as a list of integers
func _input() []int {
	var n int
	fmt.Scan(&n)
	lst := make([]int, n)
	for i := range lst {
		fmt.Scan(&lst[i])
	}
	return lst
}

// Read number of elements 'n' and size 'm' of the list 'lst'
n, m := _input()

// Initialize an empty dictionary 'l' to store the frequency of each element
l := make(map[int]int)

// Iterate through each element in the list 'lst'
for i := 0; i < n; i++ {
	// If the current element is not already present in the dictionary 'l'
	if _, ok := l[lst[i]]; !ok {
		// Add the current element to the dictionary 'l' with a frequency of 1
		l[lst[i]] = 1
	} else {
		// Increment the frequency of the current element in the dictionary 'l'
		l[lst[i]]++
	}
}

// Initialize result variable 'res' to 0
res := 0

// Iterate through each element in the list 'lst'
for i := 0; i < n; i++ {
	// If the frequency of the current element in the dictionary 'l' is greater than 1
	if l[lst[i]] > 1 {
		// Calculate the number of elements that have a smaller frequency than the current element
		// and add it to the result variable 'res'
		res += n - i - l[lst[i]]
		// Decrease the frequency of the current element in the dictionary 'l' by 1
		l[lst[i]]--
	} else {
		// Calculate the number of elements that have not been processed yet and add it to the result variable 'res'
		res += n - i - 1
	}
}

// Print the final result
fmt.Println(res)

