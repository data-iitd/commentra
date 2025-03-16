// Define lambda functions for input handling
// num_inp: takes a single input as an integer
// arr_inp: takes a list input where each element is an integer
// sp_inp: takes a list input where each element is an integer, space-separated

num_inp := func() int {
	var x int
	fmt.Scanf("%d", &x)
	return x
}
// This line reads a single integer input from the user

arr_inp := func() []int {
	var x []int
	fmt.Scanf("%v", &x)
	return x
}
// This line reads a list input from the user, where each element is an integer

sp_inp := func() []int {
	var x []int
	fmt.Scanf("%v", &x)
	return x
}
// This line reads a list input from the user, where each element is an integer, space-separated

// Read input from file instead of user input
a := sort.IntSlice(arr_inp())
// This block reads the input from the file, converts each line to a list of integers,
// and sorts the list of integers

// Find the largest number that leaves a remainder when divided by any number in the list
fmt.Println([a[0], -1][any(x%a[0] == 0 for x := a)])
// This block calculates the answer and prints it

