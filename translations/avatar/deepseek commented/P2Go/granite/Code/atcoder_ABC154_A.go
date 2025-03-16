

package main
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func solve ( S string, T string, A int, B int, U string )  {
    // Check if the string S is equal to the string U
    if S == U {
        // Decrement the count of A by 1
        A -= 1
    }
    // Check if the string T is equal to the string U
    if T == U {
        // Decrement the count of B by 1
        B -= 1
    }
    // Print the updated counts of A and B
    fmt.Printf ( "%d %d\n", A, B )
    return
}
func main ( ) {
    reader := bufio.NewReader ( os.Stdin )
    // Read the string S
    S, _ := reader.ReadString ('' )
    // Read the string T
    T, _ := reader.ReadString ('' )
    // Read the integer A
    A, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) )
    // Read the integer B
    B, _ := strconv.Atoi ( strings.TrimSpace ( reader.ReadLine ( ) )
    // Read the string U
    U, _ := reader.ReadString ( '\n' )
    // Call the solve function with the read inputs
    solve ( S, T, A, B, U )
}
// 