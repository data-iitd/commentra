// Step 1: Take two integers as input and assign them to x and y.
x, y := str_inp()

// Step 2: Calculate the maximum value between x + y - 3 and 0, with an additional condition based on (y - x) % 3.
fmt.Println(max(x+y-3+(y-x)%3>0, 0))

// Step 3: Define lambda functions for taking different types of inputs.
num_inp := func() int {
	return int(str_inp())
}
arr_inp := func() []int {
	return strings.Split(str_inp(), " ")
}
sp_inp := func() []int {
	return strings.Split(str_inp(), " ")
}
str_inp := func() string {
	return str_inp()
}

