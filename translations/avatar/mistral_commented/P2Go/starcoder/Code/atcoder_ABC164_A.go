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

    fmt.Println("Enter the values of S and W")
    S, W := readLine(reader)

    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

func readLine(reader *bufio.Reader) (int, int) {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return 0, 0
    }

    if err!= nil {
        panic(err)
    }

    str = strings.TrimRight(string(str), "\r\n")
    values := strings.Split(str, " ")

    S, _ := strconv.Atoi(values[0])
    W, _ := strconv.Atoi(values[1])

    return S, W
}

