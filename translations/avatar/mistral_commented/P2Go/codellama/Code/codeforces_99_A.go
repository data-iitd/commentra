// Get the input string from the user
l := input()

// Split the input string using '.' as delimiter and store the list in 'l'
l = strings.Split(l, ".")

// Extract the first and second parts of the list and store them in 's' and 'p' respectively
s := strings.Split(l[0], "")
p := strings.Split(l[1], "")

// Get the last character of the string 's' and store it in a variable 'last_char'
last_char := s[len(s) - 1]

// Check if the last character of the string 's' is '9'
if last_char == "9" {
    // If yes, print the message "GOTO Vasilisa."
    fmt.Println("GOTO Vasilisa.")
}

// Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
else if last_char != "9" && p[0] < "5" {
    // Concatenate all the characters of 's' to form a string
    s = strings.Join(s, "")
    // Print the string 's'
    fmt.Println(s)
}

// Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
else {
    // Concatenate all the characters of 's' to form a string
    s = strings.Join(s, "")
    // Increment the last character of the string 's' by 1
    s = strconv.Itoa(int(s) + 1)
    // Print the updated string 's'
    fmt.Println(s)
}

