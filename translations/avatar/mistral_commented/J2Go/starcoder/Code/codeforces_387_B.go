// Import necessary Go utility packages
import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Main function is the entry point of the Go application
func main() {
    // Read input from the standard input
    input, _ := os.Open(os.DevNull)
    // Comment: Use os.Open(os.Stdin) to read input from the standard input

    // Read the number of requests and preemptions from the input
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(input)))
    m, _ := strconv.Atoi(strings.TrimSpace(readLine(input)))

    // Create slices to store request and preemption indices
    req := make([]int, n)
    pre := make([]int, m)

    // Read request indices and store them in the slice
    for i := 0; i < n; i++ {
        req[i], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the slice
    for i := 0; i < m; i++ {
        pre[i], _ = strconv.Atoi(strings.TrimSpace(readLine(input)))
        // Comment: Read and store preemption index i
    }

    // Initialize index variables for requests and preemptions
    i := n - 1
    j := m - 1

    // Initialize answer variable
    ans := 0

    // While there are still requests and preemptions to compare
    for i >= 0 && j >= 0 {
        // If the current request can preempt the current preemption
        if req[i] > pre[j] {
            // Increment answer variable
            ans++
        } else {
            // Decrement preemption index
            j--
        }
        // Decrement request index
        i--
    }

    // Print the answer and the number of remaining requests
    fmt.Printf("%d %d\n", ans, i+1)
}

// readLine reads a line of input from the given reader.
func readLine(reader *bufio.Reader) string {
    line, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }
    return strings.TrimRight(string(line), "\r\n")
}

