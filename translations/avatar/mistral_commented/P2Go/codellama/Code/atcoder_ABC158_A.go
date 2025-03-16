// Read a line from the standard input
stdin := input()

// Assign the value of stdin to the variable s
s := stdin

// Initialize the variable result with "Yes" if "A" and "B" are present in s, otherwise initialize it with "No"
result := "Yes"
if !strings.Contains(s, "A") || !strings.Contains(s, "B") {
    result = "No"
}

// Print the value of the variable result
fmt.Println(result)

