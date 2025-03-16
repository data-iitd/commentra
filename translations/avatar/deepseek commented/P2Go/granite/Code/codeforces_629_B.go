

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Define the maximum number of time slots
    const N = 368

    // Initialize lists to store changes for males and females
    m := make([]int, N)
    f := make([]int, N)

    // Read the number of operations
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])

    // Read each line, strip newline, and split into gender, start time, and end time
    for i := 0; i < n; i++ {
        x, a, b := reader.ReadLine()[2 : len(reader.ReadLine())-1], reader.ReadLine()[2 : len(reader.ReadLine())-1], reader.ReadLine()[2 : len(reader.ReadLine())-1]
        a, _ = strconv.Atoi(a)
        b, _ = strconv.Atoi(b)
        b++

        // Update the changes in the lists based on gender
        if string(x[0]) == "M" {
            m[a] += 2
            m[b] -= 2
        } else {
            f[a] += 2
            f[b] -= 2
        }
    }

    // Initialize variables to store the maximum number of people and the current number of people
    a, b, c := 0, 0, 0

    // Calculate the cumulative sum of changes and find the maximum number of people at any time slot
    for i := 0; i < N; i++ {
        a += m[i]
        b += f[i]
        if min(a, b) > c {
            c = min(a, b)
        }
    }

    // Print the maximum number of people at any time slot
    fmt.Println(c)
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

