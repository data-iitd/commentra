
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize variables N and K with user input
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    K, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Create a slice 'v' of size N to store the input integers
    v := make([]int, N)

    // Read N integers from the user and store them in the slice 'v'
    for i := 0; i < N; i++ {
        v[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    // Calculate the number of subarrays of size K that can be formed from the slice 'v'
    count := ((N - 1) + ((K - 1) - 1)) / (K - 1)

    // Output the result to the console
    fmt.Println(count)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

