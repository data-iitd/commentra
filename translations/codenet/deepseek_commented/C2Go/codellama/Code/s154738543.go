package main

import "fmt"

func main() {
    // Step 3: Declare variables
    var x, y int

    // Step 4: Read input from the user
    fmt.Scanf("%d", &x)

    // Step 5: Perform the computation
    y = x * x * x

    // Step 6: Output the result
    fmt.Printf("%d\n", y)

    // Step 7: Return from the main function
    return
}
