package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))

    // Create an array to store the positions of elements
    mem := make([]int, N + 1)

    // Populate the'mem' array with the positions of each element
    for i := 1; i <= N; i++ {
        P, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n'))) // Read the element
        mem[P] = i // Store the position of the element in'mem'
    }

    // Initialize counters for the longest increasing subsequence
    maxcnt := 1 // Maximum count of increasing sequence found
    cnt := 1 // Current count of increasing sequence

    // Iterate through the'mem' array to find the longest increasing subsequence
    for i := 1; i < N; i++ {
        // Check if the current position is less than the next position
        if mem[i] < mem[i + 1] {
            cnt++ // Increment the current count if increasing
        } else {
            // Update the maximum count if the current count is greater
            maxcnt = max(maxcnt, cnt)
            cnt = 1 // Reset current count
        }
        // Check at the last element to update max count
        if i == N-1 {
            maxcnt = max(maxcnt, cnt)
        }
    }

    // Output the minimum number of elements to remove to get the longest increasing subsequence
    fmt.Println(N - maxcnt)
}

