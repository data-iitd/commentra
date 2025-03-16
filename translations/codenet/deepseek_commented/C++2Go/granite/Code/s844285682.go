
package main

import "fmt"

func main() {
    var a int // Declare an integer variable a
    
    fmt.Scan(&a) // Take an integer input from the user and store it in variable a
    
    fmt.Printf("%d:%d:%d\n", a/(60*60), a%(60*60)/60, a%(60*60)%60) // Calculate and output the hours, minutes, and seconds
    
    // 