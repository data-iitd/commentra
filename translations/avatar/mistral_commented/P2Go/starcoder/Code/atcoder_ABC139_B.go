// Get two integers from user input, separated by a space
var a, b int
fmt.Scanf("%d %d", &a, &b)

// Initialize the variable 'hole' to 1
var hole int = 1

// Initialize the variable 'i' to 0
var i int = 0

// Initialize the variable 'check' to True
var check bool = true

// Loop until the condition is not met
for check {
    // Check if the value of 'hole' is greater than or equal to 'b'
    if hole >= b {
        // If the condition is met, set 'check' to False to terminate the loop
        check = false
    } else {
        // If the condition is not met, update the value of 'hole'
        hole = a * (i + 1) - i
        // Increment the value of 'i' by 1
        i++
    }
}

// Once the loop terminates, print out the value of 'i' as the result
fmt.Println(i)

