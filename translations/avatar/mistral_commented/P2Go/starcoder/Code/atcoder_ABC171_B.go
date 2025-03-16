
// Read two integers `n` and `k` from the standard input, separated by a space
var n, k int
fmt.Scanf("%d %d", &n, &k)

// Create a list of integers from the standard input, each line containing `n` integers
var numbers []int
for i := 0; i < n; i++ {
	var number int
	fmt.Scanf("%d", &number)
	numbers = append(numbers, number)
}

// Sort the list in ascending order
sort.Ints(numbers)

// Calculate the sum of the first `k` elements of the sorted list
result := 0
for i := 0; i < k; i++ {
	result += numbers[i]
}

// Print the result
fmt.Println(result)

