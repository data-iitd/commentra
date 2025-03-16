// Read the number of currency inputs from the user
N := 0
fmt.Scan(&N)

// Create a list of converted currency values
// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
x := make([]float64, N)
for i := 0; i < N; i++ {
	var input string
	fmt.Scan(&input)
	x[i] = eval(input)
}

// Calculate and print the total sum of the converted currency values
fmt.Println(sum(x))

