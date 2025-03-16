
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Initialize variables
func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the number of elements in the array: ")
    input, _ := reader.ReadString('\n')
    N, _ := strconv.Atoi(strings.TrimSpace(input))

    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Print("Enter element ", i+1, ": ")
        input, _ := reader.ReadString('\n')
        A[i], _ = strconv.Atoi(strings.TrimSpace(input))
    }

    min_element := A[0]
    max_element := A[0]

    // Find minimum and maximum elements in the array
    for i := 0; i < N; i++ {
        if A[i] < min_element {
            min_element = A[i]
        }
        if A[i] > max_element {
            max_element = A[i]
        }
    }

    // Print the difference between maximum and minimum elements
    fmt.Printf("Difference between maximum and minimum elements: %d\n", max_element-min_element)
}

