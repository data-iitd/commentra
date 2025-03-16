
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define a function named s that takes no arguments
func s() {

    // Read input as a list of integers
    input_list := make([]int, 0)
    for _, value := range strings.Fields(string(bufio.NewReader(os.Stdin).ReadBytes('\n'))) {
        input_list = append(input_list, int(value))
    }

    // Sort the input list in ascending order
    sort.Ints(input_list)

    // Initialize a variable to store the result
    result := ""

    // Iterate through the sorted list starting from the second element
    for i := 1; i < len(input_list); i++ {

        // Compare the current element with the previous one
        current_element := input_list[i]
        previous_element := input_list[i-1]

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if current_element < previous_element*2 && current_element!= previous_element {

            // If the condition is true, set the result to 'YES'
            result = "YES"

            // Break out of the loop since we have found the answer
            break
        }
    }

    // Print the result
    fmt.Println(result)
}

