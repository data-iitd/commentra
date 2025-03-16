
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Creating a scanner to read input from the console
    scanner := bufio.NewScanner(os.Stdin)
    
    // Reading the number of elements in the array
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    
    // Initializing an array to hold the input values
    arr := make([]int, n)
    
    // Loop to read 'n' integers from the user and store them in the array
    for i := 0; i < n; i++ {
        scanner.Scan()
        arr[i], _ = strconv.Atoi(scanner.Text())
    }
    
    // Initialize the answer with the absolute value of the first element
    answer := int64(abs(arr[0]))
    
    // Loop to calculate the sum of absolute differences between consecutive elements
    for i := 1; i < n; i++ {
        answer += int64(abs(arr[i] - arr[i - 1]))
    }
    
    // Output the final calculated answer
    fmt.Println(answer)
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

