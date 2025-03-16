

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

    kTemp, err := reader.ReadString('\n')
    checkError(err)
    k, err := strconv.ParseInt(strings.TrimSpace(kTemp), 10, 64)
    checkError(err)

    arrTemp := strings.Split(strings.TrimSpace(reader.ReadLine()), " ")

    var arr []int64

    for i := 0; i < int(n); i++ {
        arrItemTemp, err := strconv.ParseInt(arrTemp[i], 10, 64)
        checkError(err)
        arrItem := arrItemTemp
        arr = append(arr, arrItem)
    }

    set := make(map[int64]bool)

    count := 0

    for i := 0; i < int(n); i++ {
        if arr[i]%k!= 0 {
            count++
            set[arr[i]] = true
        } else if _, ok := set[arr[i]/k];!ok {
            count++
            set[arr[i]] = true
        }
    }

    fmt.Println(count)

    // 