// Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
ABC := tuple(map(int, strings.Split(input(), " ")))

// Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
if ABC.count(5) == 2 {
    // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
    fmt.Println("YES")
} else {
    // If the condition is not met, print 'NO'
    fmt.Println("NO")
}

