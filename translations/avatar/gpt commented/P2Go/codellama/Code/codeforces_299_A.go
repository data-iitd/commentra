// Define a lambda function to read an integer input
num_inp := func() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Define a lambda function to read a list of integers from input
arr_inp := func() []int {
	var n int
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	return arr
}

// Define a lambda function to read a space-separated list of integers as a map object
sp_inp := func() map[int]int {
	var n int
	fmt.Scan(&n)
	arr := make(map[int]int, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		arr[x] = x
	}
	return arr
}

// Read the input from the first line of the standard input, sort it, and convert it to a list of integers
a := make([]int, 0)
fmt.Scan(&a)
sort.Ints(a)

// Check if any element in the list 'a' is not divisible by the first element of 'a'
// If all elements are divisible, print the first element; otherwise, print -1
if any(x % a[0] for x in a) {
	fmt.Println(-1)
} else {
	fmt.Println(a[0])
}

// 