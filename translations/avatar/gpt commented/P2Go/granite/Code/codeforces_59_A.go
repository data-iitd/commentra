
// Get input from the user
var txt string
fmt.Scanln(&txt)

// Initialize counters for uppercase and lowercase letters
cu := 0 // Counter for uppercase letters
cl := 0 // Counter for lowercase letters

// Iterate through each character in the input text
for _, z := range txt {
    // Check if the character is lowercase
    if unicode.IsLower(z) {
        cl++ // Increment lowercase counter
    } else {
        cu++ // Increment uppercase counter
    }
}

// Compare the counts of uppercase and lowercase letters
var out string
if cu > cl {
    // If there are more uppercase letters, convert the text to uppercase
    out = strings.ToUpper(txt)
} else {
    // If there are more lowercase letters or they are equal, convert the text to lowercase
    out = strings.ToLower(txt)
}

// Print the resulting output
fmt.Println(out)
