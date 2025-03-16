

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
)

func main() {
    // Take input from the user
    reader := bufio.NewReader(os.Stdin)
    // Read the input, split it into a list of integers, and store it in 'a'
    var n int
    fmt.Fscanf(reader, "%d\n", &n)
    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Fscanf(reader, "%d", &a[i])
    }
    // Sort the list 'a'
    sort.Ints(a)
    // Iterate through the sorted list starting from the second element
    for i := 1; i < len(a); i++ {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if a[i]!= a[i-1] && a[i] < a[i-1]*2 {
            // If the condition is met, print 'YES'
            fmt.Println("YES")
            return
        }
    }
    // If the loop completes without finding a match, print 'NO'
    fmt.Println("NO")
}
