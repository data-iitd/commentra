# Import necessary packages
package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
)

// Define helper function to read input as a list of integers
func IN ( ) []int {
    var n int
    fmt.Scan ( &n )
    a := make ( []int , n )
    for i := 0 ; i < n ; i++ {
        fmt.Scan ( &a [ i ] )
    }
    return a
}

// Define modulus constant
const mod = 1000000007

// Define main function 'main_b'
func main_b ( ) {
    // Read input string 's'
    var s string
    fmt.Scan ( &s )

    // Initialize variables 'pp' and 'na'
    pp := 0
    na := 0

    // Iterate through each character in the input string 's'
    for i := len ( s ) - 1 ; i >= 0 ; i-- {
        // Calculate current character value 'cc'
        cc := na + int ( s [ i ] - '0' )
        na = 0

        // Update 'pp' based on the current character value 'cc'
        if cc <= 4 {
            pp += cc
        } else {
            // If current character is the last character, add 1 to 'pp'
            if i == 0 {
                pp += 1
            } else {
                // Otherwise, add 10 - 'cc' to 'pp'
                pp += 10 - cc
            }
        }
    }

    // Print the result 'pp'
    fmt.Println ( pp )
}

// Define main function 'main'
func main ( ) {
    // Read input string 's'
    var s string
    fmt.Scan ( &s )

    // Initialize variables 'pmin' and 'mmin' with large initial values
    pmin := 1000
    mmin := 0

    // Add a leading zero to the input string 's'
    s = "0" + s

    // Iterate through each character in the input string 's'
    for i := len ( s ) - 1 ; i >= 0 ; i-- {
        // Calculate new minimum values 'npmin' and 'nmmin' based on current character value 'v' and previous minimum values 'pmin' and 'mmin'
        npmin := int ( math.Min ( float64 ( pmin + 10 - ( int ( s [ i ] ) - '0' + 1 ) ) , float64 ( mmin + 10 - int ( s [ i ] ) ) ) )
        nmmin := int ( math.Min ( float64 ( pmin + int ( s [ i ] ) + 1 ) , float64 ( mmin + int ( s [ i ] ) ) ) )

        // Update 'pmin' and 'mmin' with the new minimum values
        pmin = npmin
        mmin = nmmin
    }

    // Return the minimum value between 'pmin' and 'mmin'
    return int ( math.Min ( float64 ( pmin ) , float64 ( mmin ) ) )
}

// Define a helper function 'pa' to print values during testing
func pa ( v int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define function to read input from clipboard
func input_clipboard ( ) {
    // Read input text from clipboard
    input_text := os.Getenv ( "CLIPBOARD" )

    // Split input text into lines
    input_l := strings.Split ( input_text , "\n" )

    // Iterate through each line in the input text
    for _, l := range input_l {
        // Yield the current line
        yield l
    }
}

// Main program execution starts here
func main ( ) {
    // Check current platform and set input method accordingly
    if runtime.GOOS == "darwin" {
        if input_method == input_methods [ 0 ] {
            ic := input_clipboard ( )
            input = func ( ) string {
                return ic ( )
            }
        } else if input_method == input_methods [ 1 ] {
            f, _ := os.Open ( "inputFile.txt" )
            input = func ( ) string {
                var s string
                fmt.Fscan ( f , &s )
                return s
            }
        } else {
            pass
        }
        isTest = true
    } else {
        pass
    }

    // Call main function and print result
    ret := main ( )
    if ret != nil {
        fmt.Println ( ret )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'int' to convert string to integer
func int ( s string ) int {
    v, _ := strconv.Atoi ( s )
    return v
}

// Define a helper function 'float64' to convert string to float64
func float64 ( s string ) float64 {
    v, _ := strconv.ParseFloat ( s , 64 )
    return v
}

// Define a helper function 'pass' to do nothing
func pass ( ) {
    return
}

// Define a helper function 'isTest' to check if the program is running in test mode
func isTest ( ) bool {
    return false
}

// Define a helper function 'input' to read input from stdin
func input ( ) string {
    var s string
    fmt.Scan ( &s )
    return s
}

// Define a helper function 'input_methods' to store input methods
func input_methods ( ) []string {
    return []string { "clipboard" , "file" , "key" }
}

// Define a helper function 'using_method' to store the current input method
func using_method ( ) int {
    return 0
}

// Define a helper function 'input_method' to store the current input method
func input_method ( ) string {
    return input_methods ( ) [ using_method ( ) ]
}

// Define a helper function 'IN' to read input as a list of integers
func IN ( ) []int {
    var n int
    fmt.Scan ( &n )
    a := make ( []int , n )
    for i := 0 ; i < n ; i++ {
        fmt.Scan ( &a [ i ] )
    }
    return a
}

// Define a helper function 'mod' to store the modulus constant
func mod ( ) int {
    return 1000000007
}

// Define a helper function 'ret' to store the return value of the main function
func ret ( ) int {
    return 0
}

// Define a helper function 'isTest' to check if the program is running in test mode
func isTest ( ) bool {
    return false
}

// Define a helper function 'yield' to return values during testing
func yield ( v int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v []int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v []string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][][][]string ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][][][][][][][][][][]int ) {
    if isTest {
        fmt.Println ( v )
    }
}

// Define a helper function 'yield' to return values during testing
func yield ( v [][][][][]