
###
# Code
###

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize a scanner to read from the standard input
    scanner := bufio.NewScanner(os.Stdin)

    // Read the number of elements in the list 'A'
    scanner.Scan()
    N, _ := strconv.Atoi(scanner.Text())

    // Initialize an empty list 'A' with the given size 'N'
    // and read the elements from the standard input
    scanner.Scan()
    A := strings.Split(scanner.Text(), " ")

    // Initialize minimum and maximum indices'mn' and'mx'
    mn, mx := N+1, -1

    // Iterate through the list 'A' from index 0 to 'N-1'
    for i := 0; i < N; i++ {
        // Check if the current index 'i' is not equal to the next element
        if i+1!= A[i] {
            // Update the minimum and maximum indices'mn' and'mx'
            mn = int(math.Min(float64(mn), float64(i)))
            mx = int(math.Max(float64(mx), float64(i)))
        }
    }

    // Check if the maximum index'mx' is still equal to -1
    if mx == -1 {
        // If yes, print '0 0' as the output
        fmt.Println("0 0")
    } else {
        // Slice the list 'A' based on the indices'mn' and'mx+1'
        A = append(A[:mn], A[mn:mx+1][len(A[mn:mx+1])-1:]...)

        // Check if the sliced list 'A' is sorted in ascending order
        if isSorted(A) {
            // If yes, print the minimum and maximum indices'mn+1' and'mx+1' as the output
            fmt.Println(mn+1, mx+1)
        } else {
            // If no, print '0 0' as the output
            fmt.Println("0 0")
        }
    }
}

func isSorted(A []string) bool {
    for i := 0; i < len(A)-1; i++ {
        if A[i] > A[i+1] {
            return false
        }
    }
    return true
}
