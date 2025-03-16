

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
    n, err := strconv.Atoi(strings.TrimSpace(nTemp))
    checkError(err)

    kTemp, err := reader.ReadString('\n')
    checkError(err)
    k, err := strconv.Atoi(strings.TrimSpace(kTemp))
    checkError(err)

    arrTemp := strings.Split(nTemp, " ")
    var arr []int
    for i := 0; i < n; i++ {
        arrItemTemp, err := reader.ReadString('\n')
        checkError(err)
        arrItem, err := strconv.Atoi(strings.TrimSpace(arrItemTemp))
        checkError(err)
        arr = append(arr, arrItem)
    }

    var res strings.Builder

    o := 0
    e := 0

    for i := 0; i < n; i++ {
        if arr[i] == 1 {
            o++
        } else {
            e++
        }
    }

    for i := 0; i < k; i++ {
        lTemp, err := reader.ReadString('\n')
        checkError(err)
        l, err := strconv.Atoi(strings.TrimSpace(lTemp))
        checkError(err)

        rTemp, err := reader.ReadString('\n')
        checkError(err)
        r, err := strconv.Atoi(strings.TrimSpace(rTemp))
        checkError(err)

        length := r - l + 1
        if length%2!= 0 {
            res.WriteString("0\n")
        } else {
            half := length / 2
            if half <= o {
                res.WriteString("1\n")
            } else {
                res.WriteString("0\n")
            }
        }
    }

    fmt.Println(res.String())

    reader.Close()
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

