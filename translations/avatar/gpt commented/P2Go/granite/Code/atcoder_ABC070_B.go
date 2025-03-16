
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read a line of input, split it into components, and convert each component to an integer, storing them in a slice A
    reader := bufio.NewReader(os.Stdin)
    line, _, _ := reader.ReadLine()
    A := make([]int, 0)
    for _, s := range strings.Split(string(line), " ") {
        a, _ := strconv.Atoi(s)
        A = append(A, a)
    }

    // Check if the second element is less than or equal to the third element, or if the fourth element is less than or equal to the first element
    if A[1] <= A[2] || A[3] <= A[0] {
        // If the condition is true, print 0
        fmt.Println(0)
    } else {
        // If the condition is false, sort the slice A in ascending order
        for i := 0; i < len(A); i++ {
            for j := i + 1; j < len(A); j++ {
                if A[i] > A[j] {
                    A[i], A[j] = A[j], A[i]
                }
            }
        }
        // Calculate the difference between the largest and the second largest elements in the sorted slice and print the result
        fmt.Println(A[len(A)-1] - A[len(A)-2])
    }
}
