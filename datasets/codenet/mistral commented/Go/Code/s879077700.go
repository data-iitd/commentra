
package main
import "fmt"

// Declare a string variable 'a' to store user input
var a string

// Read user input using fmt.Scan() function and store it in variable 'a'
fmt.Scan(&a)

// Initialize a string variable 'ans' with value "Good"
var ans string = "Good"

// Loop through each character in the string 'a' for 3 times
for i := 0; i < 3; i++ {
    // Check if the current character is same as next character
    if a[i] == a[i+1] {
        // Update the value of 'ans' if current and next character are same
        ans = "Bad"
    }
}

// Print the final value of 'ans'
fmt.Println(ans)

