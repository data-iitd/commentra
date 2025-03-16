

package main // Step 1: Import the necessary Go utility packages.
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
func main ( ) { // Step 2: Define the main function.
    reader := bufio.NewReader ( os.Stdin ) // Step 3: Create a bufio.Reader object to read input from the user.
    fmt.Print ( "Enter the size of the array: " ) // Step 4: Prompt the user to enter the size of the array.
    text, _ := reader.ReadString ( '\n' ) // Step 5: Read the size of the array from the user.
    n, _ := strconv.Atoi ( strings.TrimSpace ( text ) ) // Step 6: Convert the input string to an integer.
    arr := make ( [] int, n ) // Step 7: Create an array to store the elements of the array.
    for i := 0 ; i < n ; i ++ { // Step 8: Read the elements of the array from the user.
        fmt.Print ( "Enter element " + strconv.Itoa ( i + 1 ) + ": " )
        text, _ := reader.ReadString ( '\n' )
        arr [ i ], _ = strconv.Atoi ( strings.TrimSpace ( text ) )
    }
    answer := int64 ( math.Abs ( float64 ( arr [ 0 ] ) ) // Step 9: Initialize a variable to store the answer.
    for i := 1 ; i < n ; i ++ { // Step 10: Calculate the absolute difference between consecutive elements and add it to the answer.
        answer += int64 ( math.Abs ( float64 ( arr [ i ] - arr [ i - 1 ] ) )
    }
    fmt.Println ( answer ) // Step 11: Print the final answer.
}
