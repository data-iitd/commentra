

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Read the value of K from the user
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter the value of K: ")
    K, _ := strconv.Atoi(reader.ReadString('\n')[0])
    // Read the string S from the user
    fmt.Print("Enter the string S: ")
    S := reader.ReadString('\n')[0]
    // Check if the length of S is less than or equal to K
    if len(S) <= K {
        // If the length of S is less than or equal to K, return S as it is
        fmt.Println(S)
    } else {
        // If the length of S is greater than K, return the first K characters of S followed by '...'
        fmt.Println(S[:K] + "...")
    }
}

