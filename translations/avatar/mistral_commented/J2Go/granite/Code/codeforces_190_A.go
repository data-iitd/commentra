
// Importing necessary packages for file I/O and collections
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function is the entry point of the Go application
func main ( ) {
    // Declaring a variable named'reader' of type 'bufio.Scanner'
    // to read input from the standard input stream
    reader := bufio.NewScanner ( os.Stdin )

    // Declaring two variables 'n' and'm' of type 'int'
    // to store the input values
    var n int
    var m int

    // Reading the first integer 'n' from the standard input
    reader.Scan ( )
    n, _ = strconv.Atoi ( strings.TrimSpace ( reader.Text ( ) )

    // Reading the second integer'm' from the standard input
    reader.Scan ( )
    m, _ = strconv.Atoi ( strings.TrimSpace ( reader.Text ( ) )

    // Checking if 'n' is equal to zero
    if n == 0 {
        // If'm' is not equal to zero, print "Impossible"
        if m!= 0 {
            fmt.Println ( "Impossible" )
        } else { // If'm' is also zero, print '0' space '0'
            fmt.Println ( 0, 0 )
        }
        // Returning from the main function
        return
    }

    // Checking if'm' is less than or equal to 'n'
    if m <= n {
        // If'm' is zero, assign it the value 1
        if m == 0 {
            m = 1
        }
        // Printing 'n' and the sum of'm' and 'n' minus one
        fmt.Println ( n, m+n-1 )
        // Returning from the main function
        return
    }

    // If'm' is greater than 'n', print'm' and the sum of'm' and 'n' minus one
    fmt.Println ( m, m+n-1 )
}

