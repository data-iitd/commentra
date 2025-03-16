package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read input from the user (not stored, just consumed)
    input, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    // Process the input sequence and return the number of pairs with common factors
    fmt.Println(nPairsWithCommonFX(strings.Split(input, " ")))
}

func nPairsWithCommonFX(sequence []string) int {
    // Initialize a dictionary to store values based on their computed factor
    storage := make(map[int][]int)
    // List to keep track of unique factors
    FXs := []int{}
    
    // Iterate through each value in the input sequence
    for _, value := range sequence {
        // Convert the string value to an integer
        value, _ := strconv.Atoi(value)
        // Compute the factor for the current value
        y := f(value)
        // If the factor is not already in storage, add it
        if y not in storage {
            storage[y] = []int{value}  // Store the value under its factor
            FXs = append(FXs, y)         // Keep track of the unique factor
        } else {
            // If the factor already exists, append the value to the existing list
            storage[y] = append(storage[y], value)
        }
    }
    
    // Calculate the total number of pairs with common factors
    // The formula counts pairs and subtracts the number of single occurrences
    return (sum(len(storage[y]) * len(storage[y]) for _, y := range FXs) - sum(len(storage[y]) for _, y := range FXs)) // 2
}

func f(n int) int {
    // Initialize the factor count
    y := 1
    // Loop until n is reduced to 1
    for n!= 1 {
        // If n is odd, increment the factor count
        if n % 2 {
            y += 1
        }
        // Divide n by 2 to reduce it
        n /= 2
    }
    // Return the total count of factors
    return y
}

func sum(s []int) int {
    total := 0
    for _, v := range s {
        total += v
    }
    return total
}

// 