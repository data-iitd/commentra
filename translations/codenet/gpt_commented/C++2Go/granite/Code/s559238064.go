
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Optimize input/output operations
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    
    // Declare variables for input and processing
    var a, b, c, d, e, f, g, T int
    var z string
    
    // Read the input string
    fmt.Fscan(reader, &z)
    
    // Get the size of the input string
    a = len(z)
    
    // Check for consecutive identical characters in the string
    for i := 0; i < a - 1; i++ {
        // If two consecutive characters are the same, print "Bad" and exit
        if z[i] == z[i + 1] {
            fmt.Fprintln(writer, "Bad")
            writer.Flush()
            return
        }
    }
    
    // If no consecutive identical characters were found, print "Good"
    fmt.Fprintln(writer, "Good")
    writer.Flush()
}

