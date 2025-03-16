
###
# Import necessary packages
###

import (
    "bufio"
    "bytes"
    "container/heap"
    "fmt"
    "os"
    "sort"
)

###
# Function to read integers from the standard input
###

func readInts() []int {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)
    var A []int
    for scanner.Scan() {
        x, _ := fmt.Sscanf(scanner.Text(), "%d")
        A = append(A, x)
    }
    return A
}

###
# Main function
###

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    const MOD = 1e9 + 7
    var n int
    fmt.Fscanf(scanner, "%d\n", &n)
    A := readInts()
    sort.Ints(A)
    ans := 0
    for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
        ans += A[i]
    }
    fmt.Println(ans)
}

###
# Run the main function if the script is run as the main module
###

func main() {
    main()
}
