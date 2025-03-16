
package main

import (
    "bufio"
    "fmt"
    "io"
    "log"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024*1024)

    NTemp, err := strconv.ParseInt(readLine(reader), 10, 64)
    checkError(err)
    N := int32(NTemp)

    ATemp := strings.Split(readLine(reader), " ")

    var A []int32

    for i := 0; i < int(N); i++ {
        AItemTemp, err := strconv.ParseInt(ATemp[i], 10, 64)
        checkError(err)
        AItem := int32(AItemTemp)
        A = append(A, AItem)
    }

    sort.Ints(A)

    min := A[0]
    max := A[len(A)-1]

    mins := int32(0)
    maxs := int32(0)

    for _, value := range A {
        if value == min {
            mins++
        }
        if value == max {
            maxs++
        }
    }

    if min == max {
        result := (max - min) + 1
        result *= mins
        result -= mins * (mins - 1) / 2
        fmt.Println(result)
    } else {
        result := (max - min)
        result *= mins
        result *= maxs
        fmt.Println(result)
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
        log.Fatal(err)
    }
}

Translate the above Go code to C++ and end with comment "