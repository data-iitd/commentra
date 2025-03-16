
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    nTemp, err := reader.ReadString('\n')
    checkError(err)
    n, err := strconv.Atoi(nTemp)
    checkError(err)

    h := make([]int, n)
    g := make([]int, n)

    for i := 0; i < n; i++ {
        hTemp, err := reader.ReadString('\n')
        checkError(err)
        h[i], err = strconv.Atoi(hTemp)
        checkError(err)

        gTemp, err := reader.ReadString('\n')
        checkError(err)
        g[i], err = strconv.Atoi(gTemp)
        checkError(err)
    }

    result := 0
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if h[i] == g[j] {
                result++
            }
        }
    }

    fmt.Println(result)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

