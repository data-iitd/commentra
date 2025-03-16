

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

    KTemp, err := reader.ReadString('\n')
    checkError(err)
    K, err := strconv.ParseInt(strings.TrimSpace(KTemp), 10, 64)
    checkError(err)

    S, err := reader.ReadString('\n')
    checkError(err)

    if int64(len(S)) <= K {
        fmt.Println(S)
    } else {
        fmt.Println(S[:K] + "...")
    }
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

Translate the above Go code to C++ and end with comment "