
// Take input from the user
var a string
fmt.Scanln(&a)

// Define a list of vowels (both lowercase and uppercase)
vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}

// Iterate through the input string in reverse order
for i := len(a) - 1; i >= 0; i-- {
    // Check if the current character is a space or a question mark
    if (a[i] =='' || a[i] == '?') {
        continue  // Skip to the next iteration if it is a space or '?'
    } else {
        // Check if the current character is a vowel
        if (contains(vo, string(a[i]))) {
            fmt.Println("YES")  // Print "YES" if it is a vowel
        } else {
            fmt.Println("NO")   // Print "NO" if it is not a vowel
        }
        break  // Exit the loop after processing the first non-space character
    }
}

func contains(s []string, e string) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

