package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read input from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter a number: ")
    source, _ := reader.ReadString('\n')

    // Check if the input length is valid (between 1 and 10 characters)
    if len(source) > 10 || len(source) < 1 {
        // Return -1 if the input length is invalid
        fmt.Println("-1")
        return
    }

    // Calculate the maximum number of combinations of '+' placements
    max_i := int(math.Pow(2, float64(len(source) - 1)))

    // Initialize a variable to hold the cumulative sum of the evaluated expressions
    sum := 0.0

    // Iterate through all possible combinations of '+' placements
    for i := 0; i < max_i; i++ {
        // Create a bitset to represent the current combination of '+' placements
        plus := strconv.FormatInt(int64(i), 2)

        // Initialize a variable to hold the current number being evaluated
        number := 0.0

        // Create a working copy of the source string to manipulate
        working := source
        // While there are still '+' placements to evaluate
        for plus!= "" {
            // Find the next position of a '1' in the bitset
            i, _ := strconv.Atoi(plus[0:1])
            // Convert the substring up to the current position to a double and add to sum
            sum += atof(working[0:i+1])
            // Shift the bitset to the right to evaluate the next segment
            plus = plus[i+1:]
            // Update the working string to remove the processed segment
            working = working[i+1:]
        }
        // Add the remaining part of the working string to the sum
        sum += atof(working)
    }

    // Set the precision for output and print the final sum
    fmt.Printf("%.0f\n", sum)
}

