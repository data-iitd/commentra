package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Take input from the user
    input, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    // Process the input and call nPairsWithCommonFX with the processed input
    fmt.Println(nPairsWithCommonFX(strings.Split(input, " ")))
}

func nPairsWithCommonFX(sequence []string) int {
    // Initialize a dictionary to store values grouped by their computed property
    storage := make(map[int][]int)
    // List to store the computed property values
    FXs := make([]int, 0)
    for _, value := range sequence {
        // Compute the property for the current value
        y := f(value)
        // If the property is not already in storage, add it with the current value
        if _, ok := storage[y];!ok {
            storage[y] = []int{value}
            FXs = append(FXs, y)
        } else {
            // Otherwise, append the current value to the list of values for this property
            storage[y] = append(storage[y], value)
        }
    }
    // Calculate the number of pairs with common factor greater than 1
    return (sum(len(storage[y]) * len(storage[y]) for _, y := range FXs) - sum(len(storage[y]) for _, y := range FXs)) / 2
}

func f(n string) int {
    // Initialize y to 1, which will be the result for the property of n
    y := 1
    for n!= "1" {
        if n[len(n)-1] == "1" {
            y += 1
        }
        n = n[:len(n)-1]
    }
    return y
}

func sum(s []int) int {
    sum := 0
    for _, v := range s {
        sum += v
    }
    return sum
}

// 