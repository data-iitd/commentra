

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    var t, m int
    fmt.Fscanf(reader, "%d %d\n", &t, &m)
    // Read the number of operations and the size of the memory

    memory := make([]int, m)
    // Initialize an array to keep track of memory allocation, all elements set to 0

    id := 1
    // Initialize the ID counter for allocated memory blocks

    for i := 0; i < t; i++ {
        // Loop through each operation
        op := strings.Split(strings.TrimSpace(readLine(reader)), " ")
        // Read the operation and split it into parts
        if op[0] == "alloc" {
            // If the operation is to allocate memory
            pos := 0
            // Initialize a position counter
            for j := 0; j < m; j++ {
                // Loop through each memory block
                if memory[j] == 0 {
                    // Check if the memory block is free
                    pos++
                    // Increment the position counter
                    if pos == int64(op[1]) {
                        // If a contiguous block of the required size is found
                        for k := j - int64(op[1])+1; k <= j; k++ {
                            memory[k] = int(id)
                        }
                        // Allocate the memory block with the current ID
                        fmt.Println(id)
                        id++
                        break
                    }
                } else {
                    pos = 0
                    // Reset the position counter if a free block is interrupted
                }
            }
            if pos!= int64(op[1]) {
                fmt.Println("NULL")
                // If no contiguous block is found, print "NULL"
            }
        }
        if op[0] == "erase" {
            // If the operation is to erase a memory block
            pos := 0
            if memory[int64(op[1])-1] == 0 || memory[int64(op[1])-1] == id {
                // Check if the specified memory block is allocated and not already free
                fmt.Println("ILLEGAL_ERASE_ARGUMENT")
                // If not, print "ILLEGAL_ERASE_ARGUMENT"
            } else {
                for j := 0; j < m; j++ {
                    if memory[j] == int64(op[1]) {
                        memory[j] = 0
                        // Free the specified memory block
                    }
                }
            }
        }
        if op[0] == "defragment" {
            // If the operation is to defragment the memory
            cnt := 0
            for j := 0; j < m; j++ {
                if memory[j] == 0 {
                    cnt++
                    // Count the number of free memory blocks
                }
            }
            memory = append(memory[:cnt], memory[cnt:]...)
            // Remove free memory blocks from the array
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

