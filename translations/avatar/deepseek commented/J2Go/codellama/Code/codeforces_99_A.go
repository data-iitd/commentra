
package main

import (
    "fmt"
    "math/big"
    "os"
    "strconv"
)

func main() {
    // Read input string from the user
    var str string
    fmt.Scanln(&str)

    // Find the index of the dot ('.') in the string
    dotIndex := 0
    for i := 0; i < len(str); i++ {
        if str[i] == '.' {
            dotIndex = i
            break
        }
    }

    // Check if the character before the dot is '9'
    if str[dotIndex-1] == '9' {
        fmt.Println("GOTO Vasilisa.")
    }
    // If the character before the dot is not '9', check the digit after the dot
    else if str[dotIndex+1] > '4' {
        // Increment the number before the dot by 1 and print the result
        _str := ""
        for i := 0; i < dotIndex; i++ {
            _str += string(str[i])
        }
        fmt.Println(big.NewInt(0).Add(big.NewInt(0).SetString(_str, 10), big.NewInt(1)).String())
    }
    // If the digit after the dot is 4 or less, print the number before the dot without any changes
    else {
        for i := 0; i < dotIndex; i++ {
            fmt.Print(str[i])
        }
        fmt.Println()
    }
}

