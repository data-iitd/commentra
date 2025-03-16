// Read input from the standard input (user input)
stdin := bufio.NewReader(os.Stdin)

// Store the input string in a variable's'
var s string

// Read the input string
s, _ = stdin.ReadString('\n')

// Check if both 'A' and 'B' are present in the input string
// If both are found, set result to "Yes", otherwise set it to "No"
result := "Yes"
if strings.Contains(s, "A") && strings.Contains(s, "B") {
    result = "Yes"
} else {
    result = "No"
}

// Print the result indicating whether both 'A' and 'B' were found
fmt.Println(result)

