// Take input string from the user
S := input()

// Import the "strings" package to use the "Count" function
import "strings"

// Create a map to count the frequency of each character in the string
c := make(map[rune]int)

// Iterate over each character in the string
for _, v := range S {
    // Increment the count of the current character
    c[v]++
}

// Create a set of unique characters from the input string
Sa := make(map[rune]struct{})

// Iterate over each character in the string
for _, v := range S {
    // Add the current character to the set
    Sa[v] = struct{}{}
}

// Check if the number of unique characters is not equal to 2
if len(Sa)!= 2 {
    // If there are not exactly 2 unique characters, print "No" and exit
    fmt.Println("No")
    return
}

// Iterate over each unique character in the set
for i := range Sa {
    // Check if the count of the current character is not equal to 2
    if c[i]!= 2 {
        // If any character does not appear exactly twice, print "No" and exit
        fmt.Println("No")
        return
    }
}

// If both conditions are satisfied, print "Yes"
fmt.Println("Yes")

