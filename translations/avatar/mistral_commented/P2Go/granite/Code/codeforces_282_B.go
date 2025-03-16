
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Take the first line as an input
    reader := bufio.NewReader(os.Stdin)
    firstline, _ := strconv.Atoi(reader.ReadLine())

    // Initialize total and memory lists
    total := 0
    memory := make([]string, 0)

    // Loop through the given number of lines
    for x := 0; x < firstline; x++ {
        // Take two integers as input, A and G
        input := reader.ReadLine()
        A, _ := strconv.Atoi(string(input[:len(input)-1-len(" ")]))
        G, _ := strconv.Atoi(string(input[len(input)-1:]))

        // Check if adding A to the total memory usage is within the limit
        if total + A <= 500 {
            // If yes, add A to the total and append 'A' to the memory list
            total += A
            memory = append(memory, "A")
        } else {
            // If no, subtract G from the total and append 'G' to the memory list
            total -= G
            memory = append(memory, "G")
        }
    }

    // Print the final memory state
    fmt.Println(memory)
}
