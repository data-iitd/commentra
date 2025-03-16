
// Read input string and set the length variable
s, l := (input(), 2019)

// Initialize a list to count occurrences of remainders, and variables for accumulated value and result
m, a, r := ([]int{1}, 0, 0)

// Iterate over the input string in reverse order
for i, e := range(strings.Split(s, "")) {
    // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
    a += int(e[0]) * pow(10, i, l)
    
    // Update the result 'r' by adding the count of occurrences of the current remainder
    r += m[a % l]
    
    // Increment the count of the current remainder in the list'm'
    m[a % l] += 1
}

// Print the final result
fmt.Println(r)

