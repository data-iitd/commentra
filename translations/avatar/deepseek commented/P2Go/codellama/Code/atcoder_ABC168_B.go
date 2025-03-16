
package main

import "fmt"

func main() {
    // Read the value of K from the user
    var K int
    fmt.Scan(&K)
    // Read the string S from the user
    var S string
    fmt.Scan(&S)
    // Check if the length of S is less than or equal to K
    if len(S) <= K {
        // If the length of S is less than or equal to K, return S as it is
        fmt.Println(S)
    } else {
        // If the length of S is greater than K, return the first K characters of S followed by '...'
        fmt.Println(S[:K] + "...")
    }
}

