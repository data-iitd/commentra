// Read input from the user and convert it to a string
s := string(input())

// Initialize an empty string to store the resulting characters
my_str := ""

// Iterate through each character in the input string
for _, c := range s {
    // Check if the character is '0' or '1'
    if c == '0' || c == '1' {
        // If it is, append it to the result string
        my_str += string(c)
    }
    // Check if the character is 'B' and the result string is not empty
    if c == 'B' && len(my_str)!= 0 {
        // If it is, remove the last character from the result string
        my_str = my_str[:len(my_str) - 1]
}

// Print the final result string
fmt.Println(my_str)

