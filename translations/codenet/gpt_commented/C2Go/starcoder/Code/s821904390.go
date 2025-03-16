package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare an integer variable to hold the input seconds
    var in int
    // Declare variables to hold hours, minutes, and seconds
    var h, m, s int

    // Read the total number of seconds from user input
    fmt.Scanf("%d", &in)

    // Calculate the number of hours by dividing total seconds by 3600
    h = in / 3600
    // Update the input seconds to the remainder after extracting hours
    in %= 3600

    // Calculate the number of minutes by dividing the remaining seconds by 60
    m = in / 60
    // Update the input seconds to the remainder after extracting minutes
    in %= 60

    // The remaining seconds are now stored in 'in'
    s = in

    // Print the result in the format of hours:minutes:seconds
    fmt.Printf("%d:%d:%d\n", h, m, s)
}

