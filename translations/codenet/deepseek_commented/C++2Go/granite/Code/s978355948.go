
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements N and the maximum distance X
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    X, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Read the lengths of the segments into a slice L
    L := make([]int, N)
    for i := 0; i < N; i++ {
        L[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Initialize the index i and the distance d
    i := 0
    d := 0

    // Loop through the segments to calculate the total distance
    for i = 0; i < N; i++ {
        // Add the current segment length to the total distance
        d = d + L[i]

        // If the total distance exceeds X, break the loop
        if d > X {
            break
        }
    }

    // Output the number of segments used
    fmt.Println(i + 1)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

