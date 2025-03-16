// Prompt the user for input and read the input string
user_input := input()

// Replace all commas in the input string with spaces
modified_input := strings.Replace(user_input, ",", " ", -1)

// Print the modified input string
fmt.Println(modified_input)

