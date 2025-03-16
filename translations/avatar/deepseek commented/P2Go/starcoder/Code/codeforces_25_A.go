
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
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
    list := make([]int, n)
    for i := 0; i < n; i++ {
        list[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }
    if sum(list) == 1 {
        fmt.Println(list.index(1) + 1)
    } else {
        fmt.Println(list.index(0) + 1)
    }
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func sum(list []int) int {
    var sum int
    for _, v := range list {
        sum += v
    }
    return sum
}

