package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin) // Initialize reader for user input
    writer := bufio.NewWriter(os.Stdout) // Initialize writer for output

    var H, W, A, B int // Declare variables for height, width, and grid dimensions

    // Read input values for H, W, A, and B
    fmt.Fscanf(reader, "%d %d %d %d\n", &H, &W, &A, &B)

    // Check if the grid dimensions meet the conditions
    if W < 2*A || H < 2*B {
        fmt.Fprintln(writer, -1) // Print -1 if the conditions are not met
        writer.Flush()            // Flush the writer to output
        return                    // Exit the program
    }

    // Write the grid to the output
    for i := 0; i < H; i++ {
        for j := 0; j < W; j++ {
            // Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if (i < B && j < A) || (i >= B && j >= A) {
                writer.WriteString("0")
            } else {
                writer.WriteString("1")
            }
        }
        writer.WriteString("\n") // Move to the next line after writing a row
    }

    // Flush the buffer to write the output to the console
    writer.Flush()
}

// <END-OF-CODE>
