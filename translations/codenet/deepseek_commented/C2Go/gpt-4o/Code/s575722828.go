package main // Step 1: Define the main package

import "fmt" // Step 2: Import the necessary package for input and output

func main() { // Step 3: Define the main function
    var S int // Step 4: Declare an integer variable S

    fmt.Scan(&S) // Step 5: Read an integer value from the user and store it in S

    // Step 6: Calculate hours, minutes, and seconds from the total seconds S
    hours := S / 3600
    minutes := (S % 3600) / 60
    seconds := S % 60

    // Step 7: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"
    fmt.Printf("%d:%d:%d\n", hours, minutes, seconds)

} // Step 8: End of the main function
// Step 9: No explicit return needed in Go
// <END-OF-CODE>
