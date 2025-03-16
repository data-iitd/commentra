// Read input from the user
n := bufio.NewReader(os.Stdin)

// Define a list of string representations of powers of ten
a := []string{"10", "100", "1000", "10000", "100000"}

// Convert the input string into a list of integers and calculate the sum
new := sum(strings.Split(n, ""))

// Check if the input is one of the predefined values in the list 'a'
if n == a {
    // If the input matches one of the predefined values, print 10
    fmt.Println(10)
} else {
    // If the input does not match, print the calculated sum
    fmt.Println(new)
}

