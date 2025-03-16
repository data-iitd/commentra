
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Creating a new Scanner object for reading input
    sc := bufio.NewScanner(os.Stdin)

    // Reading the number of character arrays to be processed
    var n int
    sc.Scan()
    fmt.Sscan(sc.Text(), &n)

    // Creating a 2D array to store the character arrays
    ss := make([][]rune, n)

    // Reading the character arrays and storing them in the 2D array
    for i := 0; i < n; i++ {
        sc.Scan()
        ss[i] = []rune(sc.Text())
    }

    // Reading the character array to be compared with the input character arrays
    sc.Scan()
    cc := []rune(sc.Text())
    m := len(cc) // Finding the length of the character array cc

    // Reading the character to be matched with the character array cc
    sc.Scan()
    c := rune(sc.Text()[0])
    c_ := c
    if c >= 'a' && c <= 'z' {
        c_ = c - 32
    } else {
        c_ = c + 32
    }

    // Creating a boolean array to keep track of the matching indices in cc
    lucky := make([]bool, m)

    // Iterating through each character in cc and comparing it with all characters in each character array in ss
    for j := 0; j < m; j++ {
        for i := 0; i < n; i++ {
            l := len(ss[i]) // Finding the length of the character array in ss at the current index i

            if m-j >= l && compare(cc[j:j+l], ss[i]) == 0 { // If the length of cc minus the current index j is greater than or equal to the length of the character array in ss at the current index i, and if the comparison of the substrings starting from the current indices in cc and ss returns 0, then set the boolean value at the current index j in lucky to true
                for h := 0; h < l; h++ { // Iterating through each character in the character array in ss at the current index i
                    lucky[j+h] = true // Setting the boolean value at the current index j+h in lucky to true
                }
            }
        }
    }

    // Iterating through each character in cc and updating it based on the boolean values in lucky
    for j := 0; j < m; j++ {
        if lucky[j] { // If the boolean value at the current index j in lucky is true
            if c == c_ { // If the character at the current index j in cc is equal to the character c in lowercase
                cc[j] = c_ // Update the character at the current index j in cc based on the character a
            } else {
                cc[j] = c // Update the character at the current index j in cc based on the character c
            }
        }
    }

    // Printing the updated character array cc
    fmt.Println(string(cc))
}

// Method to compare two character arrays aa and bb starting from their respective indices i and j
func compare(aa, bb []rune) int {
    // Iterating through the character arrays until the length m is reached
    for i, j := 0, 0; i < len(aa) && j < len(bb); i, j = i+1, j+1 {
        a := aa[i]
        b := bb[j]

        if a != b { // If characters are not equal, return the difference of their ASCII values
            return int(a - b)
        }
    }

    // If all characters match, return 0
    return 0
}

