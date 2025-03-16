// Declare a variable named 'age' and assign it the value of an integer input from the user
var age int
fmt.Scan(&age)

// Check if the value of 'age' is equal to 1
if age == 1 {
    // If the condition is met, print 'Hello World'
    fmt.Println("Hello World")
} else {
    // If the condition is not met, declare two variables 'a' and 'b' and assign them the values of two integer inputs from the user
    var a, b int
    fmt.Scan(&a, &b)
    // Print the sum of 'a' and 'b'
    fmt.Println(a + b)
}

