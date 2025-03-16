
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.ParseInt(strings.TrimSpace(nTemp), 10, 64)
    checkError(err)
    cake := make([]string, n)
    happiness := int64(0)
    chocCount := int64(0)
    nfat := int64(1)
    for i := int64(0); i < n; i++ {
        cakeTemp, err := reader.ReadString('\n')
        checkError(err)
        cake[i] = strings.TrimSpace(cakeTemp)
        for j := int64(0); j < int64(len(cake[i])); j++ {
            if string(cake[i][j]) == "C" {
                chocCount++
            }
        }
        if chocCount > 1 {
            for i := chocCount; i > chocCount-2; i-- {
                nfat *= i
            }
            happiness += nfat / 2
        }
        nfat = 1
        chocCount = 0
    }
    posCount := int64(0)
    for j := int64(0); j < n; j++ {
        for i := int64(0); i < n; i++ {
            if string(cake[i][j]) == "C" {
                chocCount++
            }
        }
        if chocCount > 1 {
            for i := chocCount; i > chocCount-2; i-- {
                nfat *= i
            }
            happiness += nfat / 2
        }
        nfat = 1
        chocCount = 0
    }
    fmt.Println(happiness)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

