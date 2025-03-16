package main // Define the main package

import (
    "bufio" // Import bufio for buffered I/O
    "fmt"   // Import fmt for formatted I/O
    "os"    // Import os for standard I/O
)

func main() {
    var buf [512]byte // Define a byte array to store the input
    reader := bufio.NewReader(os.Stdin) // Create a new buffered reader

    // Step 3: Read input from stdin
    n, _ := reader.Read(buf[:]) // Read input into the buffer

    // Step 4: Calculate the length of the input
    len := n // The length is the number of bytes read

    // Step 5: Print the first character, the length minus 3, and the second last character of the input
    fmt.Printf("%c%d%c\n", buf[0], len-3, buf[len-2])

    // Step 6: Return 0 to indicate successful execution (not needed in Go)
}

// <END-OF-CODE>
