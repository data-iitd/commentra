

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
    kTemp, err := reader.ReadString('\n')
    checkError(err)
    k, err := strconv.Atoi(kTemp)
    checkError(err)
    n++
    z := 0
    if n%k!= 0 {
        z = k - n%k
    }
    fmt.Println(n + z)
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

