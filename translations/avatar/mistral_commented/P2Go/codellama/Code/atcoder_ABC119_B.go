// Ask the user for the number of inputs
fmt.Print("Enter the number of inputs: ")
var N int
fmt.Scan(&N)

// Create a list 'x' of size 'N' using a for loop
var x []float64
for i := 0; i < N; i++ {
	var input string
	fmt.Scan(&input)
	input = strings.Replace(input, "JPY", "* 1.0", -1)
	input = strings.Replace(input, "BTC", "* 380000.0", -1)
	x = append(x, eval(input))
}

// Print the sum of all the elements in the list 'x'
fmt.Println(sum(x))

