

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
    fmt.Println("Enter the size of the square matrix:")
    nTemp, err := reader.ReadString('\n')
    if err!= nil {
        fmt.Println("Error reading input:", err)
        return
    }
    n, err := strconv.Atoi(strings.TrimSpace(nTemp))
    if err!= nil {
        fmt.Println("Invalid input for matrix size:", err)
        return
    }
    s := make([][]string, n)  // Initialize a 2D slice to store the matrix elements
    for i := 0; i < n; i++ {
        fmt.Println("Enter row", i+1, "of the matrix (space-separated values):")
        rowTemp, err := reader.ReadString('\n')
        if err!= nil {
            fmt.Println("Error reading input:", err)
            return
        }
        row := strings.Fields(strings.TrimSpace(rowTemp))
        if len(row)!= n {
            fmt.Println("Invalid input for row", i+1, ": incorrect number of values")
            return
        }
        s[i] = row
    }
    flag := 0  // Initialize flag to 0
    d1 := make([]string, n)  // Initialize a slice to store the diagonal elements from top-left to bottom-right
    d2 := make([]string, n)  // Initialize a slice to store the diagonal elements from top-right to bottom-left
    rem := make(map[string]bool)  // Initialize a map to store the non-diagonal elements
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if i == j {  // Check if the element is on the diagonal from top-left to bottom-right
                d1[i] = s[i][j]
            }
            if i == n-j-1 {  // Check if the element is on the diagonal from top-right to bottom-left
                d2[i] = s[i][j]
            }
            if i!= j && i!= n-j-1 {  // Check if the element is not on the diagonals
                rem[s[i][j]] = true
            }
        }
    }
    if len(rem)!= 1 {
        fmt.Println("NO")  // Print 'NO' if the map of non-diagonal elements does not have a single unique key
    } else if d1!= d2 {
        fmt.Println("NO")  // Print 'NO' if the two diagonals are not equal
    } else if len(rem)!= 1 {
        fmt.Println("NO")  // Print 'NO' if the diagonal elements do not all have the same value
    } else if rem[d1[0]] {
        fmt.Println("NO")  // Print 'NO' if the map of diagonal elements is equal to the map of non-diagonal elements
    } else {
        fmt.Println("YES")  // Print 'YES' if all conditions are met
    }
}
