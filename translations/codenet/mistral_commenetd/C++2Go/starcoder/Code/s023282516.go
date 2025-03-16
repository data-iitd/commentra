<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a string variable called S and read a string from the standard input
    var S string
    fmt.Scanln(&S)

    // Reverse the string S
    S = reverse(S)

    // Initialize a boolean variable called can to true
    can := true

    // Iterate through each character in the string S
    for i := 0; i < len(S); {
        // Initialize a boolean variable called can2 to false
        can2 := false

        // Iterate through each string in the divide array
        for j := 0; j < 4; j++ {
            // Get the string d from the divide array
            d := divide[j]

            // Check if the substring of S starting from the current index i and having the same size as d is equal to d
            if S[i:i+len(d)] == d {
                // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                can2 = true
                i += len(d)
            }
        }

        // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
        if!can2 {
            can = false
            break
        }
    }

    // Output "YES" if can is true, otherwise output "NO"
    if can {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

// Reverse the string S
func reverse(S string) string {
    // Initialize a string variable called S2
    var S2 string

    // Iterate through each character in the string S
    for i := len(S) - 1; i >= 0; i-- {
        // Append the current character to the end of S2
        S2 += S[i:i+1]
    }

    // Return the reversed string S2
    return S2
}

// Initialize an array of strings called divide
var divide = [...]string{"dream", "dreamer", "erase", "eraser"}

