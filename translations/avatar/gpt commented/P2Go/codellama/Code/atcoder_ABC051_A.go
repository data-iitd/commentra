// Prompt the user for input and read the input string
userInput := input()

// Replace all commas in the input string with spaces
modifiedInput := strings.Replace(userInput, ",", " ", -1)

// Print the modified input string
fmt.Println(modifiedInput)

