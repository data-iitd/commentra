

package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    fmt.Print("Enter the number of elements in the array: ")
    n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

    a := make([]int, n)

    fmt.Println("Enter the elements of the array:")
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
    }

    sort.Ints(a)

    min := a[0]

    for _, value := range a {
        if value%min!= 0 {
            fmt.Println(-1)
            return
        }
    }

    fmt.Println(min)
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == nil {
        return string(str)
    }

    return ""
}

Translate the above Go code to C++ and end with comment "