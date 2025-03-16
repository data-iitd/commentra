
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Read the input value N, which represents the number of elements.
    reader := bufio.NewReader(os.Stdin)
    N, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    // Step 2: Create a map idorder to store the elements and their corresponding positions.
    idorder := make(map[int]int)

    // Step 3: Read each element and store its value and position in the map.
    for i := 1; i <= N; i++ {
        A, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
        idorder[A] = i
    }

    // Step 4: Print the positions of the elements in the order they were read.
    for i := 1; i <= N; i++ {
        fmt.Printf("%d ", idorder[i])
    }
    fmt.Println()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

