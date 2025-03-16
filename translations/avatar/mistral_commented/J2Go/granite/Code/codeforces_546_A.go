
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declaring and initializing variables for pandu, vundu, urdu and counter c
    var pandu, vundu, urdu, c int64 = 0

    // Creating a new scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)

    // Reading the values of pandu, vundu and urdu from the console using Scanner
    scanner.Scan()
    pandu, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    vundu, _ = strconv.ParseInt(scanner.Text(), 10, 64)
    scanner.Scan()
    urdu, _ = strconv.ParseInt(scanner.Text(), 10, 64)

    // Using a for loop to calculate the sum of the series and store it in the variable c
    for i := int64(1); i <= urdu; i++ {
        c += i * pandu
        // Comment: Calculating the sum of the series using the formula: c = c + i * pandu
    }

    // Checking if the calculated sum is less than vundu
    if c < vundu {
        // Comment: If the calculated sum is less than vundu, then print "0"
        fmt.Println("0")
    } else {
        // Comment: If the calculated sum is greater than or equal to vundu, then print the difference between the calculated sum and vundu
        fmt.Println(c - vundu)
    }
}

Translate the above Go code to C++ and end with comment "