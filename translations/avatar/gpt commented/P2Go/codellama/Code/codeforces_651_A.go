// Read two integers from input and assign them to x and y
x, y := inputInt(), inputInt()

// Calculate the maximum value based on the formula and print it
// The formula computes x + y - 3 and adjusts based on the difference between y and x
// It ensures the result is not negative by taking the maximum with 0
fmt.Println(max(x + y - 3 + ((y - x) % 3 > 0), 0))

// Define a lambda function to read a single integer from input
num_inp := func() int { return inputInt() }

// Define a lambda function to read a list of integers from input
arr_inp := func() []int { return inputInts() }

// Define a lambda function to read a space-separated list of integers from input
sp_inp := func() []int { return inputInts() }

// Define a lambda function to read a string from input
str_inp := func() string { return inputStr() }

