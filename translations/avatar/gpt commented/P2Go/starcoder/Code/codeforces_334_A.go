// Read an integer input from the user
var n int
fmt.Scanf("%d", &n)

// Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
var i, j int = 1, n*n

// Loop until 'i' is less than 'j'
for ; i < j; {
    // Print the current values of 'i' and 'j'
    fmt.Printf("%d %d\n", i, j)
    
    // Increment 'i' to move towards the center
    i++
    
    // Decrement 'j' to move towards the center
    j--
}

