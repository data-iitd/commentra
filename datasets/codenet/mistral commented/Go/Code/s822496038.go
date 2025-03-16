
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Initialize a new scanner for reading input from stdin
var sc = bufio.NewScanner(os.Stdin)

// Function to read an integer from the standard input
func nextInt() int {
    // Scan the next word from the standard input
    sc.Scan()
    // Parse the scanned text as an integer
    i, err := strconv.Atoi(sc.Text())
    // If parsing fails, panic with the error
    if err != nil {
        panic(err)
    }
    // Return the parsed integer
    return i
}

// Main function
func main() {
    // Set the scanner to split input on words
    sc.Split(bufio.ScanWords)
    // Read the number of apples from the standard input
    appleNum := nextInt()
    // Read the number of pieces to be made from apples from the standard input
    pieceNum := nextInt()
    // Calculate the number of pieces made from apples
    pieceNumMadeFromApples := appleNum * 3
    // Calculate the total number of pieces
    totalPiece := pieceNumMadeFromApples + pieceNum
    // Print the total number of pieces divided by 2
    fmt.Println(totalPiece / 2)
    // End of the code
