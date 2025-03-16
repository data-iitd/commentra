
package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
)

func main() {
    // Create a new scanner to read input from the user
    scanner := bufio.NewScanner ( os.Stdin )

    // Prompt the user to enter a string
    fmt.Print ( "Enter a string: " )
    scanner.Scan ()
    S := scanner.Text ()

    // Create a map m to store the frequency of each character in the string S
    m := make ( map [rune] int )

    // Iterate through each character i in the string S
    for _, i := range S {
        // Increment the frequency of the character i in the map m
        m [ i ] ++
    }

    // Create a set Sa from the keys of the map m
    Sa := make ( map [rune] bool )
    for i := range m {
        Sa [ i ] = true
    }

    // Check if the length of the set Sa is equal to 2
    if len ( Sa )!= 2 {
        // If not, print "No" and exit the program
        fmt.Println ( "No" )
        return
    }

    // Iterate through each character i in the set Sa
    for i := range Sa {
        // Check if the frequency of the character i in the map m is equal to 2
        if m [ i ]!= 2 {
            // If the frequency of any character is not equal to 2, print "No" and exit the program
            fmt.Println ( "No" )
            return
        }
    }

    // If all characters have a frequency of 2, print "Yes" to indicate that the string satisfies the condition
    fmt.Println ( "Yes" )
}
