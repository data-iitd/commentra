

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    // Read the integer K from the standard input
    K, _ := strconv.Atoi(readln(reader))

    // Read a string S from the standard input
    S := readln(reader)

    // Check if the length of the string S is less than or equal to K
    if len(S) <= K {

        // If the condition is true, return the string S
        fmt.Println(S)
        return
    }

    // If the condition is false, return a slice of the string S
    // from the beginning to the index K, followed by three dots '...'
    fmt.Println(S[:K] + "...")
}

func readln(reader *bufio.Reader) string {
    buf, _, err := reader.ReadLine()
    if err == nil {
        return string(buf)
    }
    return ""
}

