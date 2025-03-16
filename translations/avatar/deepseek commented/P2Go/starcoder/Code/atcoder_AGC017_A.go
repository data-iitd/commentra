// Read the values of N and P from input
var N, P int
fmt.Scanf("%d %d", &N, &P)

// Define a function to calculate the binomial coefficient
func combi(N, K int) int {
    a := 1
    // Calculate the product part of the binomial coefficient
    for i := 0; i < K; i++ {
        a *= N - i
    }
    // Calculate the division part of the binomial coefficient
    for j := 0; j < K; j++ {
        a /= j + 1
    }
    return a
}

// Read a list of integers from input
var lis []int
fmt.Scanf("%d", &lis)

// Create a new list where each element is the remainder when divided by 2
var ls []int
for _, a := range lis {
    ls = append(ls, a % 2)
}

// Count the number of 1s and 0s in the list
one := 0
zero := 0
for _, a := range ls {
    if a == 1 {
        one++
    } else {
        zero++
    }
}

// Initialize variables to store the number of patterns
pattern_a := 0
pattern_b := 0

// Calculate the number of patterns with `j` zeros using the combi function
for j := 0; j <= zero; j++ {
    pattern_b += combi(zero, j)
}

// Initialize time to 0 for the while loop
time := 0

// Calculate the number of patterns with `time` ones, considering the parity with P
for ; time <= one; time++ {
    if time % 2 == P {
        pattern_a += combi(one, time)
    }
}

// Print the result as an integer by multiplying pattern_a and pattern_b
fmt.Println(pattern_a * pattern_b)

