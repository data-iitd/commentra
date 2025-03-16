// Ask the user for the number of inputs
N := int(input())

// Create a list 'x' of size 'N' using a list comprehension
x := []float64{eval(input().replace('JPY', '* 1.0').replace('BTC', '* 380000.0')) for i := 0; i < N; i++}

// Print the sum of all the elements in the list 'x'
fmt.Println(sum(x))

