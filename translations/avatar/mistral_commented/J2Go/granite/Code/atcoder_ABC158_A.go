

package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    reader = bufio.NewReader ( os.Stdin )
    writer = bufio.NewWriter ( os.Stdout )
)

func main ( ) {
    s := readString ( ) // Read the next input string

    // Check if the string contains both 'A' and 'B'
    if contains ( s, "A" ) && contains ( s, "B" ) {
        writeString ( "Yes" ) // Print "Yes" if both characters are present
    } else {
        writeString ( "No" ) // Print "No" if either character is missing
    }
}

func readString ( ) ( s string ) {
    // Function to read a string from the input
    _, err := fmt.Fscan ( reader, & s )
    if err!= nil {
        panic ( err )
    }
    return
}

func writeString ( s string ) {
    // Function to write a string to the output
    _, err := fmt.Fprintln ( writer, s )
    if err!= nil {
        panic ( err )
    }
}

func contains ( s string, c string ) bool {
    // Function to check if a string contains a substring
    return len ( s ) >= len ( c ) && s [ len ( s ) - len ( c ) : ] == c
}

