// Read the number of currency inputs from the user
N := int(input())

// Create a list of converted currency values
// For each input, replace 'JPY' with its equivalent in float and 'BTC' with its equivalent in float
x := make([]float64, N)
for i := 0; i < N; i++ {
    x[i] = eval(input().replace('JPY', '* 1.0').replace('BTC', '* 380000.0'))
}

// Calculate and print the total sum of the converted currency values
fmt.Println(sum(x))

