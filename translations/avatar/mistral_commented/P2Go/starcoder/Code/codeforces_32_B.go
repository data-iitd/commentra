// Take a string input from the user
s := input()

// Initialize an empty string to store the result
result := ""

// Initialize a variable 'i' to traverse the string's'
i := 0

// Use a while loop to traverse the string's' until the end
for i < len(s) {

    // Check if the current character is a '.'
    if s[i] == "." {

        // If yes, append '0' to the result string
        result += "0"
    } else {

        // Increment the index 'i' to move to the next character
        i++

        // Check if the next character is also a '.'
        if s[i] == "." {

            // If yes, append '1' to the result string
            result += "1"
        } else {

            // If not, append '2' to the result string
            result += "2"
        }
    }

    // Increment the index 'i' to move to the next character
    i++
}

// Print the final result string
fmt.Println(result)

