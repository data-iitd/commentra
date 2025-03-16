

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of elements: ")
    n, _ := strconv.Atoi(reader.ReadLine()[0])
    // Read the list of integers from the user input
    fmt.Print("Enter the list of integers: ")
    input := reader.ReadLine()
    a := make([]int, n)
    for i, v := range strings.Split(string(input), " ") {
        a[i], _ = strconv.Atoi(v)
    }
    
    // Initialize variables to track the current level and the number of turns
    currentLevel := 0
    counter := 0
    counterTurns := -1
    
    // Start a while loop that continues until all elements are processed
    for counter < len(a) {
        // Increment the turn counter
        counterTurns++
        // Iterate over the list 'a' to process each element
        for i := 0; i < len(a); i++ {
            // Check if the element is not -1 and is less than or equal to the current level
            if a[i]!= -1 && a[i] <= currentLevel {
                // Increment the counter and mark the element as processed
                counter++
                a[i] = -1
            }
        }
        // Reverse the list 'a' to process elements in a different order in the next iteration
        for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
            a[i], a[j] = a[j], a[i]
        }
    }
    
    // Print the number of turns taken to process all elements
    fmt.Println("Number of turns:", counterTurns)
}
