// Step 1: Take two integers as input and assign them to x and y.
var x, y int
fmt.Scanf("%d %d", &x, &y)

// Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
fmt.Println(max(x+y-3+(y-x)%3>0, 0))

// Step 3: Define lambda functions for taking different types of inputs.
num_inp := func() int {
	var x int
	fmt.Scanf("%d", &x)
	return x
}
arr_inp := func() []int {
	var x []int
	fmt.Scanf("%v", &x)
	return x
}
sp_inp := func() []int {
	var x []int
	fmt.Scanf("%v", &x)
	return x
}
str_inp := func() string {
	var x string
	fmt.Scanf("%s", &x)
	return x
}

