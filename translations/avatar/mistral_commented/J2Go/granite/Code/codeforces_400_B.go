

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initializing Scanner object for reading input
    scanner := bufio.NewScanner(os.Stdin)

    // Reading the first two integers from the input
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    m, _ := strconv.Atoi(scanner.Text())

    // Creating an array of strings to store input strings
    arrs := make([]string, n)

    // Iterating through the array and storing each string
    for i := 0; i < n; i++ {
        scanner.Scan()
        arrs[i] = scanner.Text()
    }

    // Initializing an integer array to store the length of substrings between "G" and "S"
    length := make([]int, n)
    index := 0 // Index for storing the current index in the length array
    returnDex := 0 // Index for storing the index of the string with "G" before "S"

    // Iterating through each string in the array and finding the length of substrings between "G" and "S"
    for i, tmp := range arrs {
        dexG := strings.Index(tmp, "G") // Finding the index of "G" in the current string
        dexS := strings.Index(tmp, "S") // Finding the index of "S" in the current string

        // Checking if "G" comes before "S" in the current string
        if dexG > dexS {
            returnDex = i // Storing the index of the string with "G" before "S"
            break // Exiting the loop as we have found the required string
        }

        // Storing the length of the substring between "G" and "S" in the length array
        length[index] = dexS - dexG
        index++
    }

    // Creating a HashSet to store the unique lengths of substrings
    set := make(map[int]bool)

    // Iterating through the length array and adding each unique length to the HashSet
    for _, len := range length {
        set[len] = true
    }

    // Checking if there is a string with "G" before "S"
    if returnDex == 0 {
        // Printing the result if there is no such string
        fmt.Println(returnDex)
    } else {
        // Printing the size of the HashSet if there is a string with "G" before "S"
        fmt.Println(len(set))
    }
}

These comments should provide a clear understanding of the logic behind each block of code.