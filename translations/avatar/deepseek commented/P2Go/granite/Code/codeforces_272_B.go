
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
    reader := bufio.NewReader(os.Stdin)
    fmt.Fscanf(reader, "%d\n", new(int))
    // Process the input and call nPairsWithCommonFX with the processed input
    fmt.Println(nPairsWithCommonFX(processInput(reader)))
}

func processInput(reader *bufio.Reader) []int {
    // Read the input values and convert them to integers
    input, _ := reader.ReadString('\n')
    values := strings.Split(input, " ")
    result := make([]int, len(values))
    for i, value := range values {
        result[i], _ = strconv.Atoi(value)
    }
    return result
}

func nPairsWithCommonFX(sequence []int) int {
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
    result := 0
    for _, y := range FXs {
        result += len(storage[y]) * len(storage[y])
    }
    return (result - len(FXs)) / 2
}

func f(n int) int {
    // Initialize y to 1, which will be the result for the property of n
    y := 1
    for n!= 1 {
        if n%2 == 1 {
            y++
        }
        n /= 2
    }
    return y
}

