
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
    n, _ := strconv.Atoi(readLine(reader))
    arr := make([]int, 0)
    for i := 0; i < n; i++ {
        if readInt(reader) == 1 {
            arr = append(arr, i)
        }
    }
    if len(arr) == 0 {
        fmt.Println(0)
    } else {
        result := 1
        for i := 1; i < len(arr); i++ {
            result *= arr[i] - arr[i-1]
        }
        fmt.Println(result)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return strings.TrimRight(string(str), "\r\n")
    }
    return ""
}

func readInt(reader *bufio.Reader) int {
    str := readLine(reader)
    if str == "" {
        return 0
    }
    i, err := strconv.Atoi(str)
    if err!= nil {
        return 0
    }
    return i
}

