// Take an integer 'n' as input
n := int(input())

// Initialize a list 'a' of 'n' integers by taking input
a := make([]int, n)
for i := 0; i < n; i++ {
    a[i], _ = strconv.Atoi(input())
}

// Initialize an empty list 'b' of length 'n'
b := make([]int, n)

// Assign indices to 'b' based on the values in 'a'
for i, v := range a {
    // Assign index 'i' to the position 'v - 1' in list 'b'
    b[v-1] = i
}

// Initialize a variable'res' to 0
res := 0

// Calculate the absolute difference between consecutive indices in 'b' and sum them up
for i := 1; i < n; i++ {
    // Add the absolute difference between indices 'i' and 'i-1' to'res'
    res += abs(b[i] - b[i-1])
}

// Print the final result'res'
fmt.Println(res)

