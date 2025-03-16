// Prompt the user to input their age and convert it to an integer
age := int(input())

// Check if the age is equal to 1
if age == 1 {
    // If age is 1, print 'Hello World'
    fmt.Println("Hello World")
} else {
    // If age is not 1, prompt the user to input two integers
    a, b := 0, 0
    fmt.Scanf("%d %d", &a, &b)
    // Calculate and print the sum of the two integers
    fmt.Println(a + b)
}

