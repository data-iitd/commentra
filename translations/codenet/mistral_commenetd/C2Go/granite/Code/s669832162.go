

package main // Import the standard package

import "fmt" // Import the standard input/output package

func main() { // Start of the main function
    var m1, d1, m2, d2 int // Declare four integer variables to store months and days

    // Read four integers from the standard input
    fmt.Scan(&m1, &d1, &m2, &d2)

    // Check if the first two months are equal or not
    if m1!= m2 {
        // If the months are not equal, print "1" to the standard output
        fmt.Println(1)
    } else {
        // If the months are equal, print "0" to the standard output
        fmt.Println(0)
    }
}

