
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an integer N to store the number of elements
    N := 0
    
    // Read the number of elements from user input
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    N, _ = strconv.Atoi(input)
    
    // Declare an array A of size N to hold the elements
    A := make([]int, N)
    
    // Read N elements into the array A
    for i := 0; i < N; i++ {
        input, _ := reader.ReadString('\n')
        A[i], _ = strconv.Atoi(input)
    }

    // Initialize m and M to the first element of the array A
    m := A[0]
    M := A[0]
    
    // Iterate through the array to find the minimum and maximum values
    for i := 0; i < N; i++ {
        // Update m if the current element is less than the current minimum
        if A[i] < m {
            m = A[i]
        }
        
        // Update M if the current element is greater than the current maximum
        if A[i] > M {
            M = A[i]
        }
    }

    // Output the difference between the maximum and minimum values
    fmt.Println(M - m)
}

