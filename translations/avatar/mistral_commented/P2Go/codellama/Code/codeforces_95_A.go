// Initialize variables
var pya int // Initialize a variable to store the number of strings to be processed
arre := [] // Initialize an empty list to store the strings

// Process strings input
for pya > 0 { // Iterate while pya is greater than 0
    pya-- // Decrement pya by 1
    x := input() // Get the next string
    arre = append(arre, x) // Append the string to the list
}

// Get the original string and its first letter
oString := input() // Get the original string
letter1 := input()[0] // Get the first letter of the original string

// Determine the second letter based on the first letter
letter2 := 'a' // Initialize the second letter to 'a'
if letter1 != 'a' { // If the first letter is not 'a'
    letter2 = 'b' // Set the second letter to 'b'
}

// Initialize a list of valid indices and a set to store the indices of the strings in the original string
valid := make([]int, len(oString)) // Initialize a list of zeros with the length of the original string
setcito := make(map[int]bool) // Initialize an empty set

// Find the indices of the strings in the original string
for _, x := range arre { // Iterate through the strings in the list
    for i := 0; i < len(oString); i++ { // Iterate through the indices of the string in the original string
        if oString[i:i+len(x)] == x { // If the original string contains the current string
            setcito[i] = true // Add the index to the set
        }
    }
}

// Replace the letters in the original string based on the indices of the strings
oString = []rune(oString) // Convert the string to a list
for i := range setcito { // Iterate through the indices in the set
    letter := letter1 // Initialize the letter to replace to the first letter
    if oString[i] >= 'a' && oString[i] <= 'z' { // If the letter at the index is lowercase
        letter = letter2 // Set the letter to replace to the second letter
    }
    oString[i] = rune(letter) // Replace the letter with the determined letter
}

// Print the modified string
for _, x := range oString { // Iterate through the characters of the modified string
    fmt.Print(string(x)) // Print each character of the modified string
}
fmt.Println() // Print a newline after the modified string

