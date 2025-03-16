// Define a list containing all the vowels in upper and lower case
vo := []string{"a", "e", "i", "o", "u", "y", "A", "E", "I", "O", "U", "Y"}

// Take an input string 'a' from the user
a := input()

// Iterate through the string 'a' from the end to the beginning
for i := len(a) - 1; i >= 0; i-- {
    // If the current character is a space or a question mark, skip it and move on to the next character
    if a[i] == ' ' || a[i] == '?' {
        continue
    }
    // If the current character is not a space or a question mark, check if it is a vowel or not
    else {
        // Check if the current character is a vowel
        if isVowel(a[i]) {
            // If it is, print "YES" and break out of the loop
            fmt.Println("YES")
            break
        }
        // If it is not, print "NO" and break out of the loop
        else {
            fmt.Println("NO")
            break
        }
    }
}

// Define a function to check if a given character is a vowel or not
func isVowel(c byte) bool {
    for _, v := range vo {
        if c == v[0] {
            return true
        }
    }
    return false
}

