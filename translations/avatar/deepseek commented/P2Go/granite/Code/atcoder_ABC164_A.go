
package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)
func main ( ) {
    // Read the values of S and W from a single line of input
    reader := bufio.NewReader ( os.Stdin )
    var S, W int
    fmt.Fscanf ( reader, "%d %d", & S, & W )
    // Check if the value of W is greater than or equal to S
    // If true, print "unsafe"
    if ( S <= W ) {
        fmt.Println ( "unsafe" )
    } else {
        fmt.Println ( "safe" )
    }
}
// Ensure the main function is called only when the script is executed directly
func main ( ) {
    main ( )
}
