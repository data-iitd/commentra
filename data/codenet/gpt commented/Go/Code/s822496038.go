package main

import (
    "bufio" // Importing bufio for buffered I/O
    "fmt"   // Importing fmt for formatted I/O
    "os"    // Importing os for OS functions
    "strconv" // Importing strconv for string conversion functions
)

// Initialize a new scanner to read from standard input
var sc = bufio.NewScanner(os.Stdin)

// Function to read the next integer from input
func nextInt() int {
    sc.Scan() // Read the next token from input
    i, e := strconv.Atoi(sc.Text()) // Convert the token to an integer
    if e != nil { // Check for conversion errors
        panic(e) // Panic if there is an error
    }
    return i // Return the converted integer
}

func main() {
    sc.Split(bufio.ScanWords) // Set the scanner to split input by words
    
    // Read the number of apples and pieces from input
    appleNum := nextInt() 
    pieceNum := nextInt() 
    
    // Calculate the number of pieces made from apples (3 pieces per apple)
    pieceNumMadeFromApples := appleNum * 3
    
    // Calculate the total number of pieces (pieces from apples + existing pieces)
    totalPiece := pieceNumMadeFromApples + pieceNum
    
    // Output the total number of complete sets of 2 pieces
    fmt.Println(totalPiece / 2)
}
