
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(reader.ReadLine())

    acCount := 0
    waCount := 0
    tleCount := 0
    reCount := 0
    for i := 0; i < n; i++ {
        s := reader.ReadLine()
        if string(s) == "AC" {
            acCount++
        } else if string(s) == "WA" {
            waCount++
        } else if string(s) == "TLE" {
            tleCount++
        } else if string(s) == "RE" {
            reCount++
        }
    }
    fmt.Println("AC x", acCount)
    fmt.Println("WA x", waCount)
    fmt.Println("TLE x", tleCount)
    fmt.Println("RE x", reCount)
}

