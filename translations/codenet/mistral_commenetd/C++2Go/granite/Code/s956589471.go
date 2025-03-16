

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var a, b, c, d, e, k int
    var err error

    // Read the values of these variables from the standard input using fmt.Fscanf
    _, err = fmt.Fscanf(reader, "%d %d %d %d %d %d\n", &a, &b, &c, &d, &e, &k)
    if err!= nil {
        panic(err) // If an error occurs while reading the input, panic and print the error message
    }

    // Perform a simple condition check using the relational operator <=
    if e-a <= k {
        fmt.Println("Yay!") // If the condition is true, print "Yay!" to the standard output
    } else {
        fmt.Println(":(") // If the condition is false, print ":" and a sad face "(" to the standard output
    }
}

