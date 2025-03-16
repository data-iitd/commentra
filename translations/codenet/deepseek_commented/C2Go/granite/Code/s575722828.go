
package main

import (
    "fmt"
    "os"
)

func main() {
    var S int // Step 3: Declare an integer variable S

    fmt.Fscanf(os.Stdin, "%d", &S) // Step 4: Read an integer value from the user and store it in S

    fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60) // Step 5: Calculate hours, minutes, and seconds from the total seconds S
                                                                 // Step 6: Print the calculated hours, minutes, and seconds in the format "HH:MM:SS"

    // Step 7: Return 0 to indicate successful execution
}

