
package main

import "fmt"

func main() {
    var a, b int // Declare two integer variables a and b
    
    // Read an integer input from the user, which represents time in seconds
    fmt.Scan(&a)
    
    // Calculate and display the time in hours, minutes, and seconds
    // a/(60*60) calculates the number of hours
    // a%(60*60)/60 calculates the number of minutes
    // a%(60*60)%60 calculates the remaining seconds
    fmt.Printf("%d:%d:%d\n", a/(60*60), a%(60*60)/60, a%(60*60)%60)
}

