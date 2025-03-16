

package main

import (
    "bufio"
    "fmt"
    "math/big"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    input, err := reader.ReadString('\n')
    if err!= nil {
        fmt.Println("Error reading input:", err)
        return
    }

    input = input[:len(input)-1] // Remove trailing newline character
    countOdd, err := strconv.ParseFloat(input, 64)
    if err!= nil {
        fmt.Println("Error parsing input:", err)
        return
    }

    result := new(big.Float).Quo(big.NewFloat(countOdd/2), big.NewFloat(countOdd))
    result.SetPrec(10)

    fmt.Println(result)
}

