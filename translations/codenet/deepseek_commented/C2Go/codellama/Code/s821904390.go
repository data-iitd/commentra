package main

import "fmt"

func main() {
    var in int // Declare an integer variable to store the input time in seconds
    var h, m, s int // Declare integer variables to store hours, minutes, and seconds respectively
    fmt.Scan(&in) // Read an integer input from the user, which represents the total time in seconds

    // Calculate the number of hours
    h = in / 3600 // Divide the input value by 3600 to get the number of hours
    in %= 3600 // Update in to store the remainder of the division, which represents the remaining seconds

    // Calculate the number of minutes
    m = in / 60 // Divide the updated in value by 60 to get the number of minutes
    in %= 60 // Update in to store the remainder of the division, which represents the remaining seconds

    // The remaining value in in is the number of seconds
    s = in

    // Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    fmt.Printf("%d:%d:%d\n", h, m, s)
}

