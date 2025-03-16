package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    fmt.Println("Enter the number of elements in the array:")
    nTemp, err := strconv.ParseInt(strings.TrimSpace(readLine(reader)), 10, 64)
    checkError(err)
    n := int(nTemp)

    fmt.Println("Enter the elements of the array:")
    aTemp := strings.Split(strings.TrimSpace(readLine(reader)), " ")

    var a []int64
    for i := 0; i < int(n); i++ {
        aItemTemp, err := strconv.ParseInt(aTemp[i], 10, 64)
        checkError(err)
        a = append(a, aItemTemp)
    }

    if sum(a) % (n * (n + 1) / 2)!= 0 {
        fmt.Println("NO")
    } else {
        k := sum(a) / (n * (n + 1) / 2)
        a = append(a, a[0])
        if sum(make([]int64, n))!= n {
            fmt.Println("NO")
        } else if sum(make([]int64, n))!= n {
            fmt.Println("NO")
        } else {
            fmt.Println("YES")
        }
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err!= nil {
        panic(err)
    }
}

func sum(a []int64) int64 {
    var s int64
    for _, v := range a {
        s += v
    }
    return s
}

