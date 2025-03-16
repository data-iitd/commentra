// Ask the user for a string input
s := input()

// Initialize an empty string variable to store the binary string
my_str := ""

// Iterate through each character in the user input string
for _, c := range s {
    // If the character is '0' or '1', append it to the binary string
    if c == '0' || c == '1' {
        my_str += string(c)
    }
    // If the character is 'B', remove the last character from the binary string before 'B' was encountered
    if c == 'B' && len(my_str)!= 0 {
        my_str = my_str[:len(my_str)-1]
    }
}

// Print the final binary string
fmt.Println(my_str)

