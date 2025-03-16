
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Optimize input/output operations
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)

    // Read the number of elements and the constant c
    n, _ := strconv.Atoi(read(reader))
    c, _ := strconv.Atoi(read(reader))

    // Initialize vectors to store positions and velocities
    x := make([]int, n+1)
    v := make([]int, n+1)

    // Read the positions and velocities of the elements
    for i := 1; i < n+1; i++ {
        x[i], _ = strconv.Atoi(read(reader))
        v[i], _ = strconv.Atoi(read(reader))
    }

    // Initialize vectors to store cumulative velocities from the left
    lefttotal := make([]int, n+1)
    maxlefttotal := make([]int, n+1)

    // Calculate cumulative velocities from the left
    for i := 1; i < n+1; i++ {
        lefttotal[i] = lefttotal[i-1] + v[i]
    }

    // Calculate the maximum value of lefttotal adjusted by position
    for i := 1; i < n+1; i++ {
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
    }

    // Initialize vectors to store cumulative velocities from the right
    righttotal := make([]int, n+1)
    maxrighttotal := make([]int, n+1)

    // Calculate cumulative velocities from the right
    for i := 1; i < n+1; i++ {
        righttotal[i] = righttotal[i-1] + v[n-i+1]
    }

    // Calculate the maximum value of righttotal adjusted by position
    for i := 1; i < n+1; i++ {
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c-x[n+1-i]))
    }

    // Initialize the answer variable to store the maximum result
    ans := 0

    // Evaluate the maximum possible value based on different scenarios
    for i := 1; i < n+1; i++ {
        ans = max(ans, lefttotal[i]-x[i]) // Scenario 1
        ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i]) // Scenario 2
        ans = max(ans, righttotal[i]-(c-x[n+1-i])) // Scenario 3
        ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]) // Scenario 4
    }

    // Output the final result
    fmt.Fprintln(writer, ans)

    // Flush the output buffer
    writer.Flush()
}

func read(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    s = s[:len(s)-1]
    return s
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

