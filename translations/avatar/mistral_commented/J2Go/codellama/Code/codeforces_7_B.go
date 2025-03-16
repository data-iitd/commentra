
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Reading the number of test cases
    t, _ := strconv.Atoi(os.Args[1])
    // Reading the size of the memory
    m, _ := strconv.Atoi(os.Args[2])
    // Initializing an integer array of size m to represent the memory
    memory := make([]int, m)
    // Initializing a counter for allocated memory blocks
    allocIdx := 0

    for j := 0; j < t; j++ { // Loop through each test case
        // Reading the command
        command := strings.Split(os.Args[3+j], " ")
        switch command[0] { // Reading the command
        case "alloc": // Allocate command
            // Reading the size of the block to be allocated
            n, _ := strconv.Atoi(command[1])
            // Initializing a counter for free memory blocks
            len := 0
            // Flag to check if allocation is possible
            canAlloc := false
            // Loop through the memory array
            for i := 0; i < m; i++ {
                if memory[i] == 0 { // If the current block is free
                    len++ // Increment the counter
                } else { // If the current block is allocated
                    len = 0 // Reset the counter
                }
                if len == n { // If the free memory blocks form a block of size n
                    canAlloc = true // Set the flag
                    len = i - n + 1 // Calculate the start index of the block
                    break // Exit the loop
                }
            }
            if canAlloc { // If allocation is possible
                allocIdx++ // Increment the counter for allocated blocks
                for i := len; i < len+n; i++ { // Allocate the block in the memory
                    memory[i] = allocIdx
                }
                fmt.Println(allocIdx) // Print the allocated block number
            } else { // If allocation is not possible
                fmt.Println("NULL") // Print NULL
            }
        case "erase": // Erase command
            // Reading the block number to be erased
            x, _ := strconv.Atoi(command[1])
            if x <= 0 { // If the block number is invalid
                fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Print an error message
                break
            }
            // Flag to check if the block has been erased
            hasErased := false
            // Loop through the memory array
            for i := 0; i < m; i++ {
                if memory[i] == x { // If the current block matches the given block number
                    memory[i] = 0 // Erase the block
                    hasErased = true // Set the flag
                }
            }
            if !hasErased { // If the block was not found
                fmt.Println("ILLEGAL_ERASE_ARGUMENT") // Print an error message
            }
        case "defragment": // Defragment command
            // Initializing a counter for free memory blocks
            d := 0
            // Loop through the memory array
            for i := 0; i < m; i++ {
                if memory[i] == 0 { // If the current block is free
                    d++ // Increment the counter
                }
            }
            // Calculate the new size of the memory array
            newSize := m - d
            // Create a new memory array of the new size
            newMemory := make([]int, newSize)
            // Initialize a counter for copying elements to the new array
            k := 0
            // Loop through the old memory array
            for i := 0; i < m; i++ {
                if memory[i] != 0 { // If the current block is allocated
                    newMemory[k] = memory[i] // Copy the block to the new array
                    k++ // Increment the counter
                }
            }
            memory = newMemory // Update the memory array with the new one
        default: // Invalid command
            fmt.Println("h") // Print an error message
        }
    }
}

